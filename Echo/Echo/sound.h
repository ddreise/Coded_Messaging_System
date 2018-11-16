/* 	sound.h - Interface for prototypes for Windows sound API (sound recording and playback functions)
 *  Coded Messaging System - Echo Audio
 *  ESE 3: Engineering Projects III
 *  By:			Michael Galle
 *	Edited By:	Justin Turcotte
 *				Daniel Dreise
 *				Ramtin Alikhani
 *
 *  Thursday, October 18, 2018
 */
#pragma once
// CONSTANTS - SET RECORDING TIME AND RATE
#define	DEFAULT_NSAMPLES	4000	
#define MIN_BUFSIZE			1000
#define RECORD_TIME			6		// seconds to record from mic
#define SAMPLES_SEC			8000	// number of samples per second
#define	NFREQUENCIES		96		// number of frequencies used - leave this alone

// FUNCTION PROTOTYPES
/* ************************ */
// Playback
int InitializePlayback(int sampleRate, int bitsPerSample);
int PlayBuffer(short *piBuf, long lBufSize, long timeout);
void ClosePlayback(void);

// Recording
int InitializeRecording(short* piBuf, long lSamples, int sampleRate, int bitsPerSample);
int	RecordBuffer(short *piBuf, long lBufSize, long timeout);
void CloseRecording(void);


