/*
 *      DTMF Library Header File, Based on Decoder from MultiMon
 *
 *      Copyright (C) 2004  Cooper Street Innovations
 *          Charles Eidsness <charles@cooper-street.com>
 *
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ifndef DTMF_H
#define DTMF_H

#define DTMF_FILE snd_pcm_t
#include <alsa/asoundlib.h>

int dtmf_fclose(DTMF_FILE *fd);
DTMF_FILE * dtmf_fopen(char * pcm_name, char * rw);
char dtmf_fgetc(DTMF_FILE * fd);
char *dtmf_fgets(char * tones, unsigned int tones_length, DTMF_FILE * fd);
char *dtmf_fgetl(char * tones, unsigned int tones_length, DTMF_FILE * fd);
int dtmf_fflush(DTMF_FILE * fd);


#endif
