/***************************************************************************
  \file ADM_aacadts.h
  \brief wrapper around libavcodec bitstream filter
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef ADM_AAC_ADTS
#define ADM_AAC_ADTS

#include "ADM_audioParser6_export.h"
#include "ADM_byteBuffer.h"
/**
    \class ADM_adts2aac
*/
#define ADTS_BUFFER_SIZE 16000
class ADM_AUDIOPARSER6_EXPORT ADM_adts2aac
{
private:
        bool    hasExtra;
        uint8_t extra[2];
        ADM_byteBuffer buffer;
        int     head,tail;
		
public:
    typedef enum
    {
        ADTS_OK,ADTS_ERROR,ADTS_MORE_DATA_NEEDED
    }ADTS_STATE;
		bool getExtraData(uint32_t *len,uint8_t **data);
		ADTS_STATE convert2(int incomingLen,uint8_t *intData,int *outLen,uint8_t *out);
        int  getFrequency(void);
        int  getChannels(void);
             ADM_adts2aac();
             ~ADM_adts2aac();

};
#endif

