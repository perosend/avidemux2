/**
    \file ADM_ad_lav.cpp
    \brief Audio decoders built around libavcodec
    \author mean (c) 2009

*/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include "ADM_default.h"

extern "C" {
#include "libavcodec/avcodec.h"
#include "libavutil/audioconvert.h"
}

#include "ADM_ad_plugin.h"
#include "fourcc.h"

#define ADMWA_BUF (4*1024*16) // 64 kB internal
class ADM_AudiocoderLavcodec : public     ADM_Audiocodec
{
	protected:
            typedef enum 
            {
                asInt16,asFloat,asFloatPlanar
            }ADM_outputFlavor;
            
                ADM_outputFlavor        outputFlavor;
		AVCodecContext          *_context;
		uint8_t    _buffer[ ADMWA_BUF];
		uint32_t   _tail,_head;
		uint32_t   _blockalign;
        uint32_t    channels;
        bool        decodeToS16(float *outptr,uint32_t *nbOut);
        bool        decodeToFloat(float *outptr,uint32_t *nbOut);
        bool        decodeToFloatPlanar(float *outptr,uint32_t *nbOut);
        uint32_t    outputFrequency;
	public:
                        ADM_AudiocoderLavcodec(uint32_t fourcc, WAVHeader *info, uint32_t l, uint8_t *d);
        virtual         ~ADM_AudiocoderLavcodec() ;
        virtual	bool    resetAfterSeek(void);
        virtual	uint8_t run(uint8_t *inptr, uint32_t nbIn, float *outptr, uint32_t *nbOut);
        virtual	uint8_t isCompressed(void) {return 1;}
        virtual uint32_t getOutputFrequency(void) {return outputFrequency;}
};




// Supported formats + declare our plugin
//*******************************************************

static  ad_supportedFormat Formats[]={
        {WAV_WMA,AD_MEDIUM_QUAL},
        {WAV_WMAPRO,AD_MEDIUM_QUAL},
        {WAV_QDM2,AD_MEDIUM_QUAL},
        {WAV_AMV_ADPCM,AD_MEDIUM_QUAL},
        {WAV_NELLYMOSER,AD_MEDIUM_QUAL},
        {WAV_DTS,AD_MEDIUM_QUAL},
        {WAV_MP3,AD_MEDIUM_QUAL},
        {WAV_MP2,AD_MEDIUM_QUAL},
        {WAV_AC3,AD_LOW_QUAL},   // liba52 preferred ???
        {WAV_AAC,AD_LOW_QUAL},   // libfaad preferred ???
        {0x706D,AD_LOW_QUAL},
        {WAV_EAC3,AD_MEDIUM_QUAL}

};

DECLARE_AUDIO_DECODER(ADM_AudiocoderLavcodec,						// Class
			0,0,1, 							       // Major, minor,patch
			Formats, 							// Supported formats
			"Lavcodec decoder plugin for avidemux (c) Mean/Gruntster\n"); 	// Desc
//********************************************************

uint8_t scratchPad[SCRATCH_PAD_SIZE];
/**
        \fn resetAfterSeek
*/
   bool ADM_AudiocoderLavcodec::resetAfterSeek( void )
   {
            _tail=_head=0;
            return 1;
   };
/**
        \fn ADM_AudiocoderLavcodec
*/

 ADM_AudiocoderLavcodec::ADM_AudiocoderLavcodec(uint32_t fourcc,WAVHeader *info,uint32_t l,uint8_t *d)
       :  ADM_Audiocodec(fourcc,*info)
 {
    ADM_info(" [ADM_AD_LAV] Using decoder for type 0x%x\n",info->encoding);
    ADM_info(" [ADM_AD_LAV] #of channels %d\n",info->channels);
    _tail=_head=0;
    channels=info->channels;
    _blockalign=0;
    AVCodecID codecID = AV_CODEC_ID_NONE;
    outputFrequency=info->frequency;
    bool wantFloat=true;
    switch(fourcc)
    {
      case WAV_WMAPRO:
        codecID = CODEC_ID_WMAPRO;
        break;
      case WAV_WMA:
        codecID = CODEC_ID_WMAV2;
        break;
      case WAV_QDM2:
        codecID = CODEC_ID_QDM2;
        break;
      case WAV_AMV_ADPCM:
        codecID = CODEC_ID_ADPCM_IMA_AMV;
        _blockalign=1;
        break;
      case WAV_NELLYMOSER:
        codecID = CODEC_ID_NELLYMOSER;
        _blockalign=1;
        break;
      case WAV_DTS:
        codecID = CODEC_ID_DTS;
        _blockalign = 1;
        break;
      case WAV_MP3:
        codecID = CODEC_ID_MP3;
        _blockalign = 1;
        break;
      case WAV_MP2:
        codecID = CODEC_ID_MP2;
        _blockalign = 1;
        break;
      case WAV_AC3:
        codecID = CODEC_ID_AC3;
        _blockalign = 1;
        break;
      case WAV_EAC3:
        codecID = CODEC_ID_EAC3;
        _blockalign = 1;
        break;
      case WAV_AAC:
      case 0x706D:
        codecID = CODEC_ID_AAC;
        _blockalign = 1;
        break;
      default:
             ADM_assert(0);
    }
    AVSampleFormat fmt=AV_SAMPLE_FMT_S16;
    if(wantFloat)
    {
        fmt=AV_SAMPLE_FMT_FLT;
    }
    
    AVCodec *codec=avcodec_find_decoder(codecID);
    if(!codec) {ADM_assert(0);}

    _context=avcodec_alloc_context3(codec);
    ADM_assert(_context);

    // Fills in some values...
    _context->codec_type=AVMEDIA_TYPE_AUDIO;
    _context->sample_rate = info->frequency;
    _context->channels = info->channels;
    _context->block_align = info->blockalign;
    _context->bit_rate = info->byterate*8;
    _context->sample_fmt=fmt;
    _context->request_sample_fmt=fmt;
    _context->extradata=(uint8_t *)d;
    _context->extradata_size=(int)l;
    _context->sample_fmt=AV_SAMPLE_FMT_FLT;

    if (!_blockalign) {
      _blockalign = _context->block_align;
    }

    printf("[ADM_AD_LAV] Using %d bytes of extra header data\n", _context->extradata_size);
    mixDump((uint8_t *)_context->extradata,_context->extradata_size);
    printf("\n");

    if (avcodec_open2(_context, codec, NULL) < 0)
    {
         ADM_warning("[audioCodec] Cannot use float, retrying with int16 \n");
         _context->sample_fmt=AV_SAMPLE_FMT_S16;
         if (avcodec_open2(_context, codec, NULL) < 0)
          {
              ADM_warning("[audioCodec] int16 failed also. Crashing.. \n");
              ADM_assert(0);
          }
          ADM_info("Decoder created using int16..\n");
         
    }

        switch(_context->sample_fmt)
        {
        case AV_SAMPLE_FMT_FLT:
            outputFlavor=asFloat;
            ADM_info("Decoder created using float..\n");
            break;
        case AV_SAMPLE_FMT_FLTP:
            outputFlavor=asFloatPlanar;
            ADM_info("Decoder created using float planar...\n");
            break;
        default:
            ADM_info("Decoder created using ??? %d...\n",_context->sample_fmt);
            ADM_assert(0);
            break;
        }
     


    if(!_blockalign)
    {
      if(_context->block_align) _blockalign=_context->block_align;
      else
      {
        ADM_info("[ADM_ad_lav] : no blockalign taking 378\n");
        _blockalign=378;
      }
    }
    ADM_info("[ADM_ad_lav] init successful (blockalign %d)\n",info->blockalign);
    if(_context->sample_rate!=outputFrequency)
    {
        ADM_warning("Output frequency does not match input frequency (SBR ?) : %d / %d\n",
            _context->sample_rate,outputFrequency);
        outputFrequency=_context->sample_rate;
    }
}
/**
    \fn dtor
*/
 ADM_AudiocoderLavcodec::~ADM_AudiocoderLavcodec()
 {
        avcodec_close(_context);
        av_free(_context);
}
/**
    \fn decodeToS16
*/
bool ADM_AudiocoderLavcodec::decodeToS16(float *outptr,uint32_t *nbOut)
{
int out=0;
int pout=0;
int16_t *run16;
int nbChunk;

        while(_tail-_head>=_blockalign)
        {
          nbChunk=(_tail-_head)/_blockalign;
          pout=SCRATCH_PAD_SIZE;
          AVPacket pkt;
          av_init_packet(&pkt);
          pkt.size=nbChunk*_blockalign;
          pkt.data=_buffer+_head;
          out=avcodec_decode_audio3(_context,(int16_t *)scratchPad,
                                   &pout,&pkt);

          if(out<0)
          {
            printf( "[ADM_ad_lav] *** WMA decoding error (%u)***\n",_blockalign);
            _head+=1; // Try skipping some bytes
            continue;
          }
          if(pout>=SCRATCH_PAD_SIZE)
          {
            printf("[ADM_ad_lav]Produced : %u, buffer %u,in%u\n",pout,SCRATCH_PAD_SIZE,_tail-_head);
            ADM_assert(0);
          }

//            printf("Channel layout :%llx\n",_context->channel_layout);

          if(_context->codec_id == CODEC_ID_NELLYMOSER)
          { // Hack, it returns inconsistent size
            out=nbChunk*_blockalign;
          }
          _head+=out; // consumed bytes
          // convert s16 to float...
          pout>>=1;
          *nbOut+=pout;
          run16=(int16_t *)scratchPad;
          for(int i=0;i<pout;i++)
          {
            *outptr++=((float)run16[i])/32767.;
          }
        }
    return true;
}

/**
    \fn decodeToFloat
*/

bool ADM_AudiocoderLavcodec::decodeToFloat(float *outptr,uint32_t *nbOut)
{
int out=0;
int pout=0;
int nbChunk;

        while(_tail-_head>=_blockalign)
        {
          nbChunk=(_tail-_head)/_blockalign;
          pout=SCRATCH_PAD_SIZE;

          AVPacket pkt;
          av_init_packet(&pkt);
          pkt.size=nbChunk*_blockalign;
          pkt.data=_buffer+_head;

          out=avcodec_decode_audio3(_context,(int16_t *)outptr,
                                   &pout,&pkt);
            //ADM_info("in %d out %d\n",out,pout);

          if(out<0)
          {
            ADM_warning( "[ADM_ad_lav] *** decoding error (%u)***\n",_blockalign);
            _head+=1; // Try skipping some bytes
            continue;
          }
          if(pout>=SCRATCH_PAD_SIZE)
          {
            ADM_error("[ADM_ad_lav]Produced : %u, buffer %u,in%u\n",pout,SCRATCH_PAD_SIZE,_tail-_head);
            ADM_assert(0);
          }

          _head+=out; // consumed bytes
          pout/=sizeof(float); // size in bytes -> nb float
          outptr+=pout;
          *nbOut+=pout;
        }
    return true;
}

/**
    \fn decodeToFloat
*/

bool ADM_AudiocoderLavcodec::decodeToFloatPlanar(float *outptr,uint32_t *nbOut)
{
int out=0;
int pout=0;
int nbChunk;

        while(_tail-_head>=_blockalign)
        {
          nbChunk=(_tail-_head)/_blockalign;
          pout=SCRATCH_PAD_SIZE;

          AVPacket pkt;
          av_init_packet(&pkt);
          pkt.size=nbChunk*_blockalign;
          pkt.data=_buffer+_head;

          out=avcodec_decode_audio3(_context,(int16_t *)scratchPad,
                                   &pout,&pkt);
            //ADM_info("in %d out %d\n",out,pout);

          if(out<0)
          {
            ADM_warning( "[ADM_ad_lav] *** decoding error (%u)***\n",_blockalign);
            _head+=1; // Try skipping some bytes
            continue;
          }
          if(pout>=SCRATCH_PAD_SIZE)
          {
            ADM_error("[ADM_ad_lav]Produced : %u, buffer %u,in%u\n",pout,SCRATCH_PAD_SIZE,_tail-_head);
            ADM_assert(0);
          }

          _head+=out; // consumed bytes
          pout/=sizeof(float); // size in bytes -> nb float
          int block=pout/channels;
          //printf("%d blocks\n",block);
          float *fin=(float *)scratchPad;
          float *fout=outptr;
          for(int c=0;c<channels;c++)
          {
                for(int i=0;i<block;i++)              
              {
                  fout[channels*i]=*fin;
                  fin++;
              }
              fout++;
          }
          outptr+=pout;
          *nbOut+=pout;
        }
    return true;
}
/**
    \fn run

*/
uint8_t ADM_AudiocoderLavcodec::run(uint8_t *inptr, uint32_t nbIn, float *outptr, uint32_t *nbOut)
{

        *nbOut=0;
        // Shrink
        if(_head && (_tail+nbIn)*3>ADMWA_BUF*2)
        {
            memmove(_buffer,_buffer+_head,_tail-_head);
            _tail-=_head;
            _head=0;
        }
        //
        ADM_assert(nbIn+_tail<ADMWA_BUF);
        memcpy(_buffer+_tail,inptr,nbIn);
        _tail+=nbIn;
        switch(outputFlavor)
        {
                case asInt16:        decodeToS16(outptr,nbOut);break;
                case asFloat:        decodeToFloat(outptr,nbOut);break;
                case asFloatPlanar:  decodeToFloatPlanar(outptr,nbOut);break;
                default: ADM_error("unknown output flavor\n");break;
        }

        //------------------
          if(channels>=5 )
            {
            CHANNEL_TYPE *p_ch_type = channelMapping;
#define DOIT(x,y) if(_context->channel_layout & AV_CH_##x) *(p_ch_type++)=ADM_CH_##y;

                    DOIT(FRONT_LEFT,FRONT_LEFT);
                    DOIT(FRONT_RIGHT,FRONT_RIGHT);
                    DOIT(FRONT_CENTER,FRONT_CENTER);
                    DOIT(LOW_FREQUENCY,LFE);
                    DOIT(SIDE_LEFT,REAR_LEFT);
                    DOIT(SIDE_RIGHT,REAR_RIGHT); // AV_CH_SIDE_LEFT
            }

        return 1;
}
//--- EOF


