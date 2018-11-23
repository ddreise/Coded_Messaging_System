/* message.h - Interface: Header file for File IO for getting messages from a file randomly
 *  Assignment 1 - Queues (PART 1)
 *  ESE 3: Data Structures and Algorithms
 *  By: Justin Turcotte
 * 		Michael Galle
 *  18/10/31
 */

#pragma once

#define MAX_QUOTE_LENGTH 140
#define MAX_KEY_LENGTH 25
#define INPUT_BUFFER 500

 //item is the structure containing all the data for the message
typedef struct
{
	char message[MAX_QUOTE_LENGTH]; //Message to send
	unsigned short senderId = 0;    //Id of sender
	unsigned short receiverId = 0;  //Id of receiver
	unsigned char priority = 0;     //Priority of message
	short seqNum = 0;               //Message sequence
	char key[MAX_KEY_LENGTH];		//user inputted key to identify message
} Item;

// These functions will produce the inputs to the GetMessageFromFile() function
int frandNum(int min, int max);								// Function gets a random number between min and max (max is the number of quotes in the file)
int fnumQuotes(void);										// Function returns number of quotes in the file (only need to run once)
long int* fquoteIndices(int numQuotes);						// Function returns an array that indicates the start of every quote in the file (number of characters from the start of the file) 
int* fquoteLength(int numQuotes, long int* quoteIndices);	// Function returns the smaller of the actual quote length or MAX_QUOTE_LENGTH


// Function that gets q random quote from the FortuneCookies file 
int GetMessageFromFile(char* buff, int randNum, int numQuotes, long int* quoteIndices, int* quoteLengths);	// buff is a character array (need to pass the node element that is a character array) 
int getKey(char* buff);																						//add a key to a node