/* 	sound.cpp - Implementation for functions that wrap around Windows sound API (sound recording & playback)
 *  Coded Messaging System - Echo Audio
 *  ESE 3: Engineering Projects III
 *  By:			Michael Galle
 *	Edited By:	Justin Turcotte
 *				Daniel Dreise
 *				Ramtin Alikhani
 *	
 *  Thursday, October 18, 2018
 */

#pragma comment(lib, "Ws2_32.lib")	   // Make sure we are linking against the Ws2_32.lib library
#pragma comment(lib, "Winmm.lib")      // Make sure we are linking against the Winmm.lib library - some functions/symbols from this library (Windows sound API) are used
#include <stdio.h> 
#include <windows.h>					// Contains WAVEFORMATEX structure
#include <mmsystem.h>					
#include <math.h>
#include "sound.h"

// output and input channel parameters
static	HWAVEOUT	HWaveOut;				/* Handle of opened WAVE Out and In device */
static  HWAVEIN		HWaveIn;
static	WAVEFORMATEX WaveFormat;			/* WAVEFORMATEX structure for reading in the WAVE fmt chunk */
static  WAVEHDR	WaveHeader[NFREQUENCIES];	/* WAVEHDR structures - 1 per buffer */
static  WAVEHDR	WaveHeaderSilence;
static  WAVEHDR WaveHeaderIn;

/* PLAYBACK FUNCTIONS */
/* ********************************************************************************************* */
// Prototypes needed 
void SetupFormat(WAVEFORMATEX *wf, int sampleRate, int bitsPerSample);			// Used by InitializePlayback()					
int WaitOnHeader(WAVEHDR *wh, char cDit, long timeout);							// Used by Playbuffer()

int	InitializePlayback(int sampleRate, int bitsPerSample)
{
	int		rc;
	// set up the format structure, needed for playback (and recording)
	SetupFormat(&WaveFormat, sampleRate, bitsPerSample);
	// open the playback device
	rc = waveOutOpen(&HWaveOut, WAVE_MAPPER, &WaveFormat, (DWORD)NULL, 0, CALLBACK_NULL);
	if (rc) {
		printf("Unable to open Output sound Device! Error %x.", rc);
		return(-5);
	}
	return(0);
}

// Function needed by InitializePlayback() 
/* SetupFormat() initializes a WAVEFORMATEX structure to the required parameters (sample rate, bits per sample, etc) */
static void SetupFormat(WAVEFORMATEX *wf, int sampleRate, int bitsPerSample)
{
	wf->wFormatTag = WAVE_FORMAT_PCM;
	wf->nChannels = 1;
	wf->nSamplesPerSec = sampleRate;
	wf->wBitsPerSample = bitsPerSample;
	wf->nBlockAlign = wf->nChannels * (wf->wBitsPerSample / 8);
	wf->nAvgBytesPerSec = wf->nSamplesPerSec * wf->nBlockAlign;
	wf->cbSize = 0;
	return;
}

/* PlayBuffer() */
int PlayBuffer(short *piBuf, long lSamples, long timeout)
{
	static	WAVEFORMATEX WaveFormat;	/* WAVEFORMATEX structure for reading in the WAVE fmt chunk */
	static  WAVEHDR	WaveHeader;			/* WAVEHDR structure for this buffer */
	MMRESULT	mmErr;
	int		rc;

	// stop previous note (just in case)
	waveOutReset(HWaveOut);   // is this good?

	// get the header ready for playback
	WaveHeader.lpData = (char *)piBuf;
	WaveHeader.dwBufferLength = lSamples;
	rc = waveOutPrepareHeader(HWaveOut, &WaveHeader, sizeof(WAVEHDR));
	if (rc) {
		printf("Failed preparing WAVEHDR, error 0x%x.", rc);
		return(-3);
	}
	WaveHeader.dwFlags &= ~(WHDR_BEGINLOOP | WHDR_ENDLOOP);

	// play the buffer. This is NON-blocking.
	mmErr = waveOutWrite(HWaveOut, &WaveHeader, sizeof(WAVEHDR));
	// wait for completion
	rc = WaitOnHeader(&WaveHeader, 0, timeout);
	// give back resources
	waveOutUnprepareHeader(HWaveOut, &WaveHeader, sizeof(WAVEHDR));
	return(rc);
}

// Function needed by Playbuffer()
static int WaitOnHeader(WAVEHDR *wh, char cDit, long timeout)
{
	long	lTime = 0;
	// wait for whatever is being played, to finish. Quit after timeout seconds.
	for (; ; ) {
		if (wh->dwFlags & WHDR_DONE) return(0);
		// idle for a bit so as to free CPU
		Sleep(100L);
		lTime += 100;
		if (lTime >= timeout) return(-4);  // timeout period
		if (cDit) printf("%c", cDit);
	}
}

void ClosePlayback(void)
{
	int		i;
	for (i = 0; i < NFREQUENCIES; ++i) {
		waveOutUnprepareHeader(HWaveOut, &WaveHeader[i], sizeof(WAVEHDR));
	}
	// close the playback device
	waveOutClose(HWaveOut);
	return;
}

/* RECORDING FUNCTIONS */
/* ********************************************************************************************* */
int InitializeRecording(short* piBuf, long lBufSize, int sampleRate, int bitsPerSample)
{
	MMRESULT rc;

	// set up the format structure, needed for recording.
	SetupFormat(&WaveFormat, sampleRate, bitsPerSample);

	// open the recording device
	rc = waveInOpen(&HWaveIn, WAVE_MAPPER, &WaveFormat, (DWORD)NULL, 0, CALLBACK_NULL);
	if (rc) {
		printf("Unable to open Input sound Device! Error %x.", rc);
		return(-2);
	}

	// prepare the buffer header for use later on
	WaveHeaderIn.lpData = (char *)piBuf;
	WaveHeaderIn.dwBufferLength = lBufSize;
	rc = waveInPrepareHeader(HWaveIn, &WaveHeaderIn, sizeof(WAVEHDR));
	if (rc) {
		printf("Failed preparing input WAVEHDR, error 0x%x.", rc);
		return(-3);
	}

	return(0);

}

int	RecordBuffer(short *piBuf, long lBufSize, long timeout)
{
	static	WAVEFORMATEX WaveFormat;	/* WAVEFORMATEX structure for reading in the WAVE fmt chunk */
	static  WAVEHDR	WaveHeader;			/* WAVEHDR structure for this buffer */
	MMRESULT	mmErr;
	int		rc;

	printf("Recording now.....");

	// stop previous recording (just in case)
	waveInReset(HWaveIn);   // is this good?

	// get the header ready for recording.  This should not be needed here AND in init.
	WaveHeader.lpData = (char *)piBuf;
	WaveHeader.dwBufferLength = lBufSize;
	rc = waveInPrepareHeader(HWaveIn, &WaveHeader, sizeof(WAVEHDR));
	if (rc) {
		printf("Failed preparing WAVEHDR, error 0x%x.", rc);
		return(0);
	}
	WaveHeader.dwFlags &= ~(WHDR_BEGINLOOP | WHDR_ENDLOOP);

	// Give the buffer to the recording device to fill.
	mmErr = waveInAddBuffer(HWaveIn, &WaveHeader, sizeof(WAVEHDR));
	// Record the buffer. This is NON-blocking.
	mmErr = waveInStart(HWaveIn);
	// wait for completion
	rc = WaitOnHeader(&WaveHeader, '.', timeout);
	// stop input
	waveInStop(HWaveIn);
	return(rc);
}

void CloseRecording(void)
{
	waveInUnprepareHeader(HWaveIn, &WaveHeaderIn, sizeof(WAVEHDR));
	// close the playback device
	waveInClose(HWaveIn);
	return;
}

