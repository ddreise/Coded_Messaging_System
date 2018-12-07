/* 	Echo_Compress.cpp
*	Implementation to compress audio
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


// Definitions and libraries
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Echo_Compress.h"

unsigned char* compressedAudio;

// Wrapper function for compression
int compressAudio(unsigned char* audio, int iInLen) {
	
	unsigned char *input;						// input pointer array
	unsigned char *output;						// output pointer array
	long int length;							// variable to hold the length of the compressed string
	
	input = (unsigned char*)calloc(strlen((const char*)audio), sizeof(char));
	output = (unsigned char*)calloc(strlen((const char*)audio), sizeof(char));

	//int iInLen = strlen((const char*)audio);			// get length of buffer
	int iOutLen = strlen((const char*)audio);

	length = RLEncode(audio, iInLen, output, iOutLen, ESCAPECHAR);		// ENCODE MESSAGE

	return(0);
}

// Wrapper function for decompression
int decompressAudio(unsigned char* audio, int iInLen){
	
	unsigned char *input;
	unsigned char *output;
	long int length;

	input = (unsigned char*)calloc(strlen((const char*)audio), sizeof(char));
	output = (unsigned char*)calloc(strlen((const char*)audio), sizeof(char));

	//int iInLen = strlen((const char*)audio);			// get length of buffer
	int iOutLen = strlen((const char*)audio);

	length = RLDecode(audio, iInLen, output, iOutLen, ESCAPECHAR);

	return(0);
}


// Function to ENCODE message
int RLEncode(unsigned char* input, int iInLen, unsigned char* output, int iOutLen, unsigned char charEsc) {

	unsigned char c = NULL;							// variable to hold current character at pointer location
	unsigned char tempbuff[10] = { NULL };			// temp buffer with room for RLE sequence
	int count = 1;									// repetition counter variable
	int i = 0, j = 0;								// looping variable
	output[0] = '\0';								// Set so can use strcat()

	while (strlen((char*)output) < iInLen) {
		for (i = 0; i < iInLen; i++) {					// repeat loop until "i" reaches the length of the input string
			c = input[i];								// set character at pointer location to variable c
			while (input[i] == input[i + 1]) {			// loop if the current character is the same as the next character in the string
				c = input[i];							// set character at pointer location to varaible c
				count++;								// increase repetition counter by 1
				i++;									// increase loop counter by 1
			}
			if (count > 3) {														// if repetition counter is greater than c, start compression sequence...
				sprintf((char*)tempbuff, "%c%02x%c", charEsc, count, c);			// print string to temporary buffer consisting of the escape character, the number of repeats, and the repeated character itself
				strcat((char*)output, (char*)tempbuff);								// append the temporary buffer string to the output string (attach to the end)
				count = 1;															// reset repetition counter
			}

			else if (count <= 3) {													// if repetition counter is less than or equal 3, do not start compression sequence...
				for (j = 0; j < count; j++) {										// begin loop to store character in buffer
					sprintf((char*)tempbuff, "%c", c);								// print character to temporary buffer	
					strcat((char*)output, (char*)tempbuff);							// append the character in the temporary buffer to the output buffer
				}
				count = 1;															// reset repetition counter
			}
		}

		compressedAudio = output;						// for easy access to functions outside

		return(strlen((char*)output));					// return string length of compressed buffer
	}

	printf("Error: Compression Overflow!");
	return(1);
}

// Function to DECODE message
int RLDecode(unsigned char *input, int iInLen, unsigned char *output, int iOutLen, unsigned char charEsc) {

	unsigned char c[2] = { NULL };					// variable to hold current character WITH null terminator (for strcat)
	unsigned char HEX[3] = { NULL };				// array to hold RLE sequence (ex// 0x1b04a where 0x1b is the designated character, 04 is number of repeats, a is the character repeated
	int count = 1;						// repetition counter variable
	char temp;
	output[0] = '\0';					// So so can use strcat()
	int i, j;							// looping variables


	while (strlen((char*)output) < iInLen) {
		for (i = 0; i < iInLen; i++) {				// loop sequence for the length of the string
			if (input[i] != charEsc) {				// As long as the current character in array is not the 'special' character...
				c[0] = input[i];					// set first location of character array to pointed to character in input string
				c[1] = '\0';						// set second location of character array to null terminator for strcat usage
				strcat((char*)output, (char*)c);	// put character into output buffer
			}

			if (input[i] == charEsc) {				// As long as the current character IS the 'special' character...

				count = 1;							// reset counter variable

				HEX[0] = input[++i];			// holds number of repeats (first hex digit)
				HEX[1] = input[++i];			// holds number of repeats (second hex digit) repeated character (change from hex to integer)
				HEX[2] = '\0'; 					// set last character to null terminator for strcat
				i++;

				count = (int)strtol((const char*)HEX, NULL, 16);		// used to convert the HEX value to INTEGER value

				for (j = 0; j < count; j++) {			// copy the character equal to 'count' times to output
					c[0] = input[i];
					c[1] = '\0';
					strcat((char*)output, (char*)c);
				}
			}
		}
		return (strlen((char*)output));				// return the string length
	}

	printf("Error: Decompression Overflow!");
	return(1);

}

unsigned char* getCompressedAudio(void) {
	return compressedAudio;
}
