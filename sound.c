#include <stdio.h>
#include <math.h>
#include "sound.h"

// this function takes 1 second of samples (16000 in our case) and calculate 80 peices of RMS value
// and turn these values into decibels, and display them as a barchart
void displayWAVDATA(short s[]){
	double rms[80];		// because we have 16000 samples, therefore every 2++ samples make one RMS

	int i, j;			// nested loop counters
	short *ptr = s;

	for(i=0; i<80; i++){		// outer loop repeats 80 times
		double sum = 0;			// initialize the sum
		for(j=0; j<200; j++){
			sum += (*ptr) * (*ptr);		// accumulate the sum
			ptr++;						// pointer omcrements
		}
		rms[i] = sqrt(sum/200);
		printf("RMS[%d] = %f\n", i, rms[i]);
	}
}

void showID(char *name, char *value){
	printf("%s ", name);
	for(int i=0; i<4; i++)
		printf("%c", value[i]);
	puts("");			// \n
}

// function definition
void displayWAVHDR(struct WAVHDR h){
	showID("chunk ID", h.ChunkID);
	printf("Chunk size %d\n", h.ChunkSize);
	showID("Format", h.Format);
	showID("Subchunk1 ID", h.Subchunk1ID);
	printf("Subchunk1 size %d\n", h.Subchunk1Size);
	printf("Audio format: %d\n", h.AudioFormat);
	printf("Num of channels: %d\n", h.NumChannels);
	printf("Sample rate: %d\n", h.SampleRate);
	printf("Byte rate: %d\n", h.ByteRate);
	printf("Block align: %d\n", h.BlockAlign);
	printf("Bits per sample: %d\n", h.BitsPerSample);
	showID("Subchunk 2 ID", h.Subchunk2ID);
	printf("Subchunk 2 size: %d\n", h.Subchunk2Size);
}
