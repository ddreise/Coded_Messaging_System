/* 	audio_handling.cpp - Implementation to customize the use of the recording and playback functions of sound.h
 *  Coded Messaging System - Echo Audio
 *  ESE 3: Engineering Projects III
 *  By: Justin Turcotte
 * 		Daniel Dreise
 *		Ramtin Alikhani
 *  Thursday, October 18, 2018
 */

#define _CRT_SECURE_NO_WARNINGS

#include "sound.h"
#include "audio_handling.h"
#include <stdio.h>
#include <windows.h>

 //	Program must:
 //		record n seconds of audio
 //		playback n seconds of audio
 //		8 bits / sample
 //		8KHz sample rate
 //	Program could:
 //		have adjustable bits per sample and sample rate

//VARIABLE DELCARATIONS//
short* iBigBuf;
long lBigBufSize;

static int iRecSec = 0;
static int bitsPerSample = 0;
static float sampleRate = 0;

int iIn;						//used for user decisions

//FUNCTION DEFINITIONS//

//wrapper that interfaces with audio recording software
int echoRecord(void)
{
	//obtain desired recording values
	iRecSec = 0;
	while (iRecSec < 1)
	{
		printf("Welcome to recording!\n"
			"Please enter how many seconds you would like to record for (ex: 10): ");
		scanf("%d", &iRecSec);				//take how many seconds to record for from user
		
		//error check
		if (iRecSec < 1) printf("\nERROR: Please enter a valid amount of time to record for (POSITVIE INTEGER NUMBER > 0)!\n");
	}

	bitsPerSample = 0;
	while (bitsPerSample == 0)
	{
		printf("Please choose how many bits per sample: (Must choose 8 or 16)\n"
			"1) 8 bits per sample\n"
			"2) 16 bits per sample\n");
		scanf("%d", &iIn);					//take user choice

		switch (iIn)
		{
		case 1:
			bitsPerSample = 8;
			break;
		case 2:
			bitsPerSample = 16;
			break;
		default:
			printf("ERROR: Please enter 1 for 8 bits per sample or 2 for 16 bits per sample!\n");
			break;
		}
	}

	sampleRate = 0;
	while (sampleRate == 0)
	{
		printf("Enter the desired sample rate in KHz (ex: 8): ");
		scanf("%f", &sampleRate);			//take the sample rate
		sampleRate = sampleRate * 1000;		//converts the sample rate to KHz

		if (sampleRate == 0) printf("\nERROR: Please enter a positive non-zero value!\n");
	}

	//set the buffers
	//if bitspersample is 16 bits, buffer must be doubled! - so easy fix is to double recording time
	if (bitsPerSample == 16) iRecSec *= 2;

	lBigBufSize = iRecSec * (long)sampleRate;
	iBigBuf = (short*)malloc(iRecSec * sampleRate);
	if (iBigBuf == NULL)
	{
		printf("\nERROR: Unable to allocate space required for audio buffer!\n");
		return -1;
	}

	//execute recording!
	InitializeRecording(iBigBuf, lBigBufSize, sampleRate, bitsPerSample);		//prepare for recording
	RecordBuffer(iBigBuf, lBigBufSize);											//record!
	CloseRecording();															//close recording

	return 0;
}

//wrapper that interfaces with audio playback software
int echoPlayback(void)
{
	printf("Welcome to playback!\n"
		"Audio will be played back with the settings entered during recording:\n");

	//execute playback!
	InitializePlayback(sampleRate, bitsPerSample);
	PlayBuffer(iBigBuf, lBigBufSize);
	ClosePlayback();

	return 0;
}