/**
    \file ADM_JSDebug.h
    \brief Debug oriented functions for avidemux JS/JS shell
    \author mean (c) 2009 fixounet@free.fr


*/
/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef ADMJS_DEBUG_H
#define ADMJS_DEBUG_H
#ifdef __cplusplus
extern "C"
{
#endif
void jsPopupError(const char *s);
void jsPopupInfo(const char *s);
void jsPrint(const char *s);
void jsPrint2(const char *s);
void jsHelp(const char *s);
#ifdef __cplusplus
};
#endif

#endif