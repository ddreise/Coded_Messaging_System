/* 	Echo_Message.h
 *	Interface to handle functions required by both sending and receiving messages
 *
 *  Coded Messaging System - Echo
 *  ESE 3: Engineering Projects III
 *
 *  By: Justin Turcotte
 * 		Daniel Dreise
 *		Ramtin Alikhani
 *
 *  Thursday, November 9, 2018
 */

#ifndef ECHO_MESSAGE_H
#define ECHO_MESSAGE_H

//constants
#define COM_LENGTH 5
#define MAX_ID_LENGTH 11
#define AUDIO_MESSAGE_SIZE 80000

//structure for header of audio message frame
typedef struct FRAME_AUDIO_HEADER
{
	char senderID[MAX_ID_LENGTH];	//holds id of sender, limit of 10 characters
	long audioSize;					//holds the size of the audio (80000 per frame IF the frame is full)
	short secOfAudio;				//holds the amount of seconds of audio recorded
	short bitsPerSample;			//holds the bits per sample of the audio
	short sampleRate;				//holds the sample rate used for the audio
	char lastFrame;					//holds if this frame is the last frame to be sent/received

}FRAME_AUDIO_HEADER;

//structure for complete audio message frame
typedef struct FRAME_AUDIO_MESSAGE
{
	FRAME_AUDIO_HEADER audioHeader;		//header for the audio frame
	short audio[AUDIO_MESSAGE_SIZE];	//storage for audio data
};

#endif