/* 	audio_handling.h - Interface to customize the use of the recording and playback functions of sound.h
 *  Coded Messaging System - Echo Audio
 *  ESE 3: Engineering Projects III
 *  By: Justin Turcotte
 * 		Daniel Dreise
 *		Ramtin Alikhani
 *  Thursday, October 18, 2018
 */

#pragma once

 //	Program must:
 //		record n seconds of audio
 //		playback n seconds of audio
 //		8 bits / sample
 //		8KHz sample rate
 //	Program could:
 //		have adjustable bits per sample and sample rate

//PROTOTYPES//
long getAudioSize(void);		//get the size of the audio
void setAudioSize(long audioSize);		//set the size of audio externally

short* getAudio(void);			//get the audio data
void setAudio(short* audio);	//set the audio data externally

int audioSetup(void);	//wrapper to handle audio settings
int audioRecord(void);	//wrapper to handle audio recording
int audioPlayback(void); //wrapper to handle audio playback