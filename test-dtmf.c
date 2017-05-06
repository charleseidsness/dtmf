/*
 *      DTMF Library Test, Based on Decoder from MultiMon
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

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <dtmf.h>

int main(int argc, char* argv[])
{
	char tones[256];
	int opt;
	DTMF_FILE * fd = dtmf_fopen("au1000","r");
	if (fd == NULL) exit(10);

	while((opt = getopt(argc, argv, "slc")) != -1) {
		switch(opt) {
		case 's':
			printf("TEST 1: dtmf_fgets\n\tEnter a number sequence followed by #.\n");
			dtmf_fgets(tones, 256, fd);
			printf("\tTones returned: %s\n",tones);
			break;
		case 'l':
			printf("TEST 2: dtmf_fgetl\n\tQuickly enter a number sequence.\n");
			dtmf_fgetl(tones, 256, fd);
			printf("\tTones returned: %s\n",tones);
			break;
		case 'c':
			printf("TEST 3: dtmf_fgetc\n\tQuickly enter a number.\n");
			tones [1] = '\0';
			tones[0] = dtmf_fgetc(fd);
			printf("\tTone returned: %s\n",tones);
			break;
		default:
			printf("Usage:\n");
			printf("\tTest dtmf_fgets -s\n");
			printf("\tTest dtmf_fgetl -l\n");
			printf("\tTest dtmf_fgetc -c\n");
			break;
		}
	}

	dtmf_fclose(fd);
	exit(0);
}

