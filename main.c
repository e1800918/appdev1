// This is main.c
#include <stdio.h>
#include <signal.h>
#include "screen.h"     // for user-defined header, use double quotes
#include <stdlib.h>
#include "sound.h"
int main(){
	FILE *f;
	short sd[RATE];					// for all samples in 1 sec
	while(1){
		int ret = system(CMD);
		if(ret == SIGINT) break;
		f =  fopen("test.wav", "r");	// open the file for read only
    	clearScreen();
    	setColors(WHITE, bg(CYAN));
		if(f == NULL){
			printf("cannot open the wav file\n");
			return 1;
		}
		struct WAVHDR h;				// instance of wav header
		fread(&h, sizeof(h), 1, f);		// read wav header to each
		displayWAVHDR(h);				// show wav header instuction
		fread(&sd, sizeof(sd), 1, f);
		displayWAVDATA(sd);
		fclose(f);						// close the opened file
	}
    resetColors();
    getchar();
}

