/***************************************************************************
    \file    automation.cpp
    \author  (C) 2002 by mean fixounet@free.fr
    \brief   This file reads the command line and do the corresponding command

 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include <math.h>
#include "ADM_cpp.h"
#include "ADM_assert.h"
#include "avi_vars.h"
#include "ADM_script2/include/ADM_script.h"
#include "prefs.h"
#include "A_functions.h"

#include "ADM_debugID.h"
#define MODULE_NAME  MODULE_COMMANDLINE
#include "ADM_debug.h"

#include "ADM_vidMisc.h"
#include "ADM_videoEncoderApi.h"
#include "DIA_factory.h"
#include "ADM_slave.h"
#include "ADM_iso639.h"

extern void UI_setVideoCodec( int i);
extern void UI_setAudioCodec( int i);
extern uint8_t audioCodecSetByName( int dex,const char *name);

static uint8_t scriptAddVar(char *var,char *value);
static void show_info(char *p);
void call_scriptEngine(const char *scriptFile);
static void call_buildtimemap( char *p);
static void call_quit(char *p) ;
static void setBegin(char *p)   ;
static void setEnd(char *p)      ;
//static void saveRawAudio(char *p)      ;
static void call_normalize(char *p) ;
static void call_resample(char *p) 	;
static void call_help(char *p) 	;
static void call_setAudio(char *p) 	;
//static void call_load(char *p) 	;
static void call_autosplit(char *p) 	;
static void call_fps(char *p) 	;
static void call_audiocodec(char *p) 	;
static void call_videocodec(char *p) ;
static void call_videoconf(char *p) ;
static int searchReactionTable(char *string);
static void call_setPP(char *v,char *s);
static void call_slave(char *p);
//static void call_v2v(char *a,char *b,char *c);
static void call_probePat(char *p);
static void list_audio_languages(char *p);
static void save(char*name);

//extern uint8_t A_setContainer(const char *cont);

static int call_bframe(void);
static int call_x264(void);
static int call_forcesmart(void);
static int set_output_format(const char *str);
static void set_reuse_2pass_log(char *p);
static void setVar(char *in);
//
uint8_t trueFalse(char *p);
//_________________________________________________________________________


int global_argc;
char **global_argv;
//extern uint8_t	ADM_saveRaw(const char *name );
//_________________________________________________________________________

typedef void (*one_arg_type)(char *arg);
typedef	void (*two_arg_type)(char *arg,char *otherarg);
typedef	void (*three_arg_type)(char *arg,char *otherarg,char *yetother);
//_________________________________________________________________________

typedef struct
{
          const char    *string;
          uint8_t       have_arg;
          const char    *help_string;
          one_arg_type   callback;
}AUTOMATON;
//_________________________________________________________________________

#define avs_port_change "avisynth-port"
AUTOMATON reaction_table[]=
{
	
	{"nogui",                  0, "Run in silent mode",                                                        (one_arg_type)GUI_Quiet},
	{"slave",                  1, "run as slave, master is on port arg",                                       (one_arg_type)call_slave},
	{"run",                    1, "load and run a script",                                                     (one_arg_type)call_scriptEngine},

	{"save-jpg",               1, "save a jpeg",                                                               (one_arg_type)A_saveJpg},
	{"begin",                  1, "set start frame",                                                           (one_arg_type)setBegin},

	{"end",                    1, "set end frame",                                                             (one_arg_type)setEnd},
	{"save-raw-audio",         1, "save audio as-is ",                                                         (one_arg_type)A_saveAudioCopy},
	{"save-uncompressed-audio",1, "save uncompressed audio",                                                   (one_arg_type)A_saveAudioProcessed},
	{"load",                   1, "load video or workbench",                                                   (one_arg_type)A_openAvi},

	{"load-workbench",         1, "load workbench file",                                                       (one_arg_type)A_openAvi},
	{"append",                 1, "append video",                                                              (one_arg_type)A_appendAvi},
	{"save",                   1, "save avi",                                                                  (one_arg_type)save},

	{"force-b-frame",          0, "Force detection of bframe in next loaded file",                             (one_arg_type)call_bframe},
	{"force-alt-h264",         0, "Force use of alternate read mode for h264",                                 (one_arg_type)call_x264},

	{"external-audio",         2, "Load an external audio file. {track_index} {filename}",                     (one_arg_type)A_externalAudioTrack},
	{"set-audio-language",     2, "Set language of an active audio track {track_index} {language_short_name}", (one_arg_type)A_setAudioLang},

	{"audio-delay",            1, "set audio time shift in ms (+ or -)",                                       (one_arg_type)call_setAudio},
	{"audio-codec",            1, "set audio codec (MP2/MP3/AC3/NONE (WAV PCM)/TWOLAME/COPY)",                 (one_arg_type)call_audiocodec},
	{"video-codec",            1, "set video codec (Divx/Xvid/FFmpeg4/VCD/SVCD/DVD/XVCD/XSVCD/COPY)",          (one_arg_type)call_videocodec},

	{"video-conf",             1, "set video codec conf (cq=q|cbr=br|2pass=size)[,mbr=br][,matrix=(0|1|2|3)]", (one_arg_type)call_videoconf},
	{"reuse-2pass-log",        0, "reuse 2pass logfile if it exists",                                          (one_arg_type)set_reuse_2pass_log},
	{"autosplit",              1, "split every N MBytes",                                                      (one_arg_type)call_autosplit},
	{"info",                   0, "show information about loaded video and audio streams",                     (one_arg_type)show_info},


	{"output-format",          1, "set output format (AVI|OGM|ES|PS|AVI_DUAL|AVI_UNP|...)",                    (one_arg_type)set_output_format},
	{"rebuild-index",          0, "rebuild index with correct frame type",                                     (one_arg_type)A_rebuildKeyFrame},
	{"var",                    1, "set var (--var myvar=3)",                                                   (one_arg_type)setVar},
	{"help",                   0, "print this",                                                                (one_arg_type)call_help},
	{"quit",                   0, "exit avidemux",                                                             (one_arg_type)call_quit},
	{"probePat",               1, "Probe for PAT//PMT..",                                                      (one_arg_type)call_probePat},
	{"list-audio-languages",   0, "list all available audio langues",                                          (one_arg_type)list_audio_languages},
	{avs_port_change,          1, "set avsproxy port accordingly",                                             (one_arg_type)A_set_avisynth_port}

};
#define NB_AUTO (sizeof(reaction_table)/sizeof(AUTOMATON))
//_________________________________________________________________________

typedef enum {
	SOME_UNKNOWN,
	MPEG2ENC_VCD,    // pseudo codec with profile
	MPEG2ENC_SVCD,   // pseudo codec with profile
	MPEG2ENC_DVD     // pseudo codec with profile
} codec_t;

//void automation(int argc, char **argv)
int automation(void )

{
static char **argv;
static int argc;
static int cur;
static int myargc;
static int index;
static three_arg_type three;
static two_arg_type two;

        argc=global_argc;
	argv = global_argv;

          //the port change has to be done before the video load
          for( int runParaSearch=2 ; runParaSearch < argc ; ){
		      if(*argv[runParaSearch] == '-' && *(argv[runParaSearch]+1) == '-')
			  {
			      index = searchReactionTable(argv[runParaSearch]+2);
				  if(index != -1)
				  {
                      if(!strcmp(avs_port_change, argv[runParaSearch] +2 ))
				  	  {
                          A_set_avisynth_port(argv[runParaSearch+1]);
                          break;
				  	  }
			          runParaSearch += reaction_table[index].have_arg +1;
			      }
				  else
				      runParaSearch += 1;
		      }
			  else
			      runParaSearch += 1;
		  }

          printf("\n *** Automated : %"PRIu32" entries*************\n",(uint32_t)NB_AUTO);
          // we need to process
          argc-=1;
          cur=1;
          myargc=argc;
          while(myargc>0)
          {
                      if(( *argv[cur]!='-') || (*(argv[cur]+1)!='-'))
                      {
                            if(cur==1)
                            {
								A_openAvi(argv[cur]);
                            }
                            else
                                printf("\n Found garbage %s\n",argv[cur]);
                            cur+=1;myargc-=1;
                            continue;
                      }
                      // else it begins with --
                      index= searchReactionTable(argv[cur]+2);
                      if(index==-1) // not found
                      {
                                                      printf("\n Unknown command :%s\n",argv[cur] );
                                                      cur+=1;myargc-=1;
                      }
                      else
                      {
                          printf("%s-->%d\n", reaction_table[index].string,reaction_table[index].have_arg);
                          one_arg_type call=reaction_table[index].callback;
                          switch(  reaction_table[index].have_arg)
                          {
                              case 3:
                                        three=(three_arg_type)call;
                                        three( argv[cur+1],argv[cur+2],argv[cur+3]);
                                        break;
                              case 2:
                                        two=(two_arg_type)call;
                                        two( argv[cur+1],argv[cur+2]);
                                        break;
                              case 1:
                                        call(argv[cur+1]);
                                        break;
                              case 0:
                                        call(NULL);
                                        break;
                              default:
                                        ADM_assert(0);
                                        break;
                          }
                          cur+=1+reaction_table[index].have_arg;
                          myargc-=1+reaction_table[index].have_arg;
                      }
          } // end while
          GUI_Verbose();
          printf("\n ********** Automation ended***********\n");
          return 0; // Do not call me anymore
}
//_________________________________________________________________________

int searchReactionTable(char *string)
{
    for(unsigned int j=0;j<NB_AUTO;j++)
    {
            if(!strcmp(string,reaction_table[j].string))
                  return j;
    }
    return -1;
}

void call_scriptEngine(const char *scriptFile)
{
	char *root, *ext;
	bool executed = false;

	std::vector<IScriptEngine*> engines = getScriptEngines();
	ADM_PathSplit(scriptFile, &root, &ext);

	if (engines.size() == 1)
	{
		A_parseScript(engines[0], scriptFile);
		executed = true;
	}
	else
	{
		for (int i = 0; i < engines.size(); i++)
		{
			if (engines[i]->defaultFileExtension().compare(ext) == 0)
			{
				A_parseScript(engines[i], scriptFile);
				executed = true;
				break;
			}
		}
	}

	if (!executed)
	{
		printf("Unable to appropriate script engine for script file\n");
	}
}

void call_quit        (char *p) { UNUSED_ARG(p); exit(0);                            }
// The form is name=value
// split it in two
void setVar(char *in)
{
char *equal;
        equal=strstr(in,"=");
        if(!equal)
        {
                printf("Malformed set var  %s (name=value)\n",in);
                return ;
        }
        if(in+strlen(in)==equal)
        {
                printf("No value after =  %s (name=value)\n",in);
                return ;
        }
        *equal=0; // Remove =

        if(!scriptAddVar(in,equal+1))
                printf("Warning setvar failed\n");

}




void call_buildtimemap(char *p) { UNUSED_ARG(p); aprintf("timemap\n");      }

void call_setPP(char *v,char *s)
{
// TODO


}
void call_setAudio (char *p)
{

		int32_t i;
		sscanf(p,"%"PRIi32,&i);
//		audioFilterDelay(i);
}
void call_audiocodec(char *p)
{
     audioCodecSetByName( 0,p);    
     
}
void call_probePat(char *p)
{
// BAZOOKA  runProbe(p);
}
void call_videocodec(char *p)
{
    int ix=videoEncoder6_GetIndexFromName(p);
    if(ix!=-1)
    {

        videoEncoder6_SetCurrentEncoder(ix);
        UI_setVideoCodec(ix);
    }
	

}
static void call_videoconf(char *p)
{
	//videoCodecConfigure(p,0,NULL);

    //videoEncoder6Configure

}
void call_slave(char *p)
{
		uint32_t i;
		sscanf(p,"%"PRIu32,&i);
		printf("Slace on port  %"PRIu32"\n",i);
		if(!ADM_slaveConnect(i))
        {
                ADM_error("Cannot connect to master\n");
                exit(-1);
        }
}
void call_fps(char *p)
{

		float fps;
		aviInfo info;

		if (avifileinfo)
		{
			video_body->getVideoInfo(&info);
			sscanf(p,"%f",&fps);
			printf("\n Frames per Second %f\n",fps);
			info.fps1000 = (uint32_t) (floor (fps * 1000.+0.49));
			video_body->updateVideoInfo (&info);
			video_body->getVideoInfo (avifileinfo);
		} else
		{
			printf("\n No Video loaded; ignoring --fps\n");
		}
}
void call_autosplit(char *p)
{

		int32_t i;
		sscanf(p,"%"PRIi32,&i);
//		ADM_aviSetSplitSize(i);
}

void setBegin(char *p)
{

}
void setEnd(char *p)
{
}
void call_help(char *p)
{
    UNUSED_ARG(p);
    printf("\n Command line possible arguments :");
    for(unsigned int i=0;i<NB_AUTO;i++)
      {
          printf("\n    --%s, %s ", reaction_table[i].string,reaction_table[i].help_string);
          switch(reaction_table[i].have_arg)
          {
                  case 0:	 printf(" ( no arg )");break;
                  case 1:	 printf(" (one arg )");break;
                  case 2:	 printf(" (two args )");break;
                  case 3:	 printf(" (three args) ");break;

          }

      }
    printf("\n");

                    call_quit(NULL);
}

void list_audio_languages(char *p){
	UNUSED_ARG(p);
	printf("\n Available audio languages:\nShort  |  LanguageName\n----------------------");
	const ADM_iso639_t *languages = ADM_getLanguageList();
	for(size_t i=0; i<ADM_getLanguageListSize(); i++){
		int skipAfter = 5-strlen(languages[i].iso639_2);
		printf("\n\t%s",languages[i].iso639_2);
		while(skipAfter-- >0)
			printf(" ");
		printf("\t-\t%s",languages[i].eng_name);
	}
	printf("\n\n");
	call_quit(NULL);
}

void save(char*name)
{
    if(!video_body->getNbSegment()) return;
	A_Save(name);
}



void show_info(char *p){
   UNUSED_ARG(p);
   uint32_t war,har;
   const char *s;

   if (avifileinfo)
    {

   printf("Video\n");
   printf("   Video Size: %u x %u\n", avifileinfo->width, avifileinfo->height);
   printf("   Frame Rate: %2.3f fps\n", (float)avifileinfo->fps1000/1000.F);
   printf("   Number of frames: %d frames\n", avifileinfo->nb_frames);
   printf("   Codec FourCC: %s\n", fourCC::tostring(avifileinfo->fcc));
   if(avifileinfo->nb_frames){
     uint32_t hh, mm, ss, ms;
      frame2time(avifileinfo->nb_frames, avifileinfo->fps1000,&hh, &mm, &ss, &ms);
      printf("   Duration: %02d:%02d:%02d.%03d\n", hh, mm, ss, ms);
   }else{
      printf("   Duration: 00:00:00.000\n");
   }
   war=video_body->getPARWidth();
   har=video_body->getPARHeight();
   getAspectRatioFromAR(war,har, &s);
   printf("   Aspect Ratio: %s (%u:%u)\n", s,war,har);

   printf("Audio\n");
   ADM_audioStream *s;
   WAVHeader *wavinfo=NULL;
   video_body->getDefaultAudioTrack(&s);
   if(s )
   {
        wavinfo=s->getInfo();
    }
   if( wavinfo )
    {
      printf("   Codec: %s\n",getStrFromAudioCodec(wavinfo->encoding));
      printf("   Mode: ");
      switch( wavinfo->channels ){
         case 1:  printf("MONO\n"); break;
         case 2:  printf("STEREO\n"); break;
         default: printf("????\n"); break;
      }
      printf("   BitRate: %u Bps / %u kbps\n", wavinfo->byterate, wavinfo->byterate*8/1000);
      printf("   Frequency: %u Hz\n", wavinfo->frequency);
   }else{
      printf("   Codec: NONE\n");
      printf("   Mode: NONE\n");
      printf("   BitRate: NONE\n");
      printf("   Frequency: NONE\n");
      printf("   Duration: NONE\n");
    }
   }
   else
   {
   	printf("Nothing to get infos from\n");
   }
}
int call_bframe(void)
{
	video_body->setEnv(ENV_EDITOR_BFRAME);
	return 1;
}
int call_x264(void)
{
	video_body->setEnv(ENV_EDITOR_X264);
	return 1;
}

int call_packedvop(void)
{
	video_body->setEnv(ENV_EDITOR_PVOP);
	return 1;
}
int call_forcesmart(void)
{
	video_body->setEnv(ENV_EDITOR_SMART);
	return 1;
}
int set_output_format(const char *str)
{
    if(false==video_body->setContainer(str,NULL))
    {
        printf("Cannot set that container\n");
        
    }
    return 0;
}

/*
        return 0 if p is 0 or false or off
        else 1

*/
uint8_t trueFalse(char *p)
{
int notdigit=0;
        if(!p) return 0; // should not happen...

        int l=strlen(p);
        for(int i=0;i<l;i++) if(!isdigit(p[i])) notdigit=1;
        if(!notdigit) // looks like a digit
        {
                l=atoi(p);
                if(l) return 1;
                return 0;
        }
        // It is a string

        uint8_t ret=1;

        if(!strcasecmp(p,"off")) ret=0;
        if(!strcasecmp(p,"false")) ret=0;


        return ret;

}
#define ADM_MAX_VAR 50
typedef struct scriptVar
{
        char *name;
        char *string;
        int  isString;
}scriptVar;


static scriptVar myVars[ADM_MAX_VAR];
uint32_t nbVar=0;

/*
        Push a var into the stack var

*/
uint8_t scriptAddVar(char *var,char *value)
{
        video_body->setVar(var,value);
        return 1;

}
/*
       Retrieve a var in the stack

*/



void set_reuse_2pass_log(char *p){
   prefs->set(FEATURES_REUSE_2PASS_LOG,true);
}
//EOF
