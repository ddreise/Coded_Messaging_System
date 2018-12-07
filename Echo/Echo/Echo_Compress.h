/* 	Echo_Compress.h
*	Interface to compress audio
*
*  Coded Messaging System - Echo
*  ESE 3: Engineering Projects III
*
*  By: Justin Turcotte
* 		Daniel Dreise
*		Ramtin Alikhani
*
*  Friday, November 30, 2018
*/

#ifndef ECHO_COMPRESS_H
#define ECHO_COMPRESS_H
#define ESCAPECHAR 27

// Prototype functions
int compressAudio(unsigned char* audio, int iInLen);
int RLEncode(unsigned char *input, int iInLen, unsigned char *output, int iOutLen, unsigned char cEscape);
int RLDecode(unsigned char *input, int iInLen, unsigned char *output, int iOutLen, unsigned char cEscape);
unsigned char* getCompressedAudio(void);


#endif