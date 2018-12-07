/* 	Echo_Frame.h
*	Interface to handle frame of Echo (send/receive random quotes)
*
*  Coded Messaging System - Echo
*  ESE 3: Engineering Projects III
*
*  By: Justin Turcotte
* 		Daniel Dreise
*		Ramtin Alikhani
*
*  Thursday, November 23, 2018
*/

#ifndef ECHO_FRAME_H
#define ECHO_FRAME_H

#include <Windows.h>

//defines
#define MAX_QUOTE_LENGTH 140

//enum for menu choices
typedef enum FRAME_MENU_CHOICE
{
	FRAME_FAIL,
	FRAME_SEND_TEXT_MESSAGE,
	FRAME_SEND_RANDOM_QUOTE,
	FRAME_SEND_MULTIPLE_TEXT,
	FRAME_RECEIVE_TEXT_MESSAGE,
	FRAME_RECEIVE_MULTIPLE_TEXT,
	FRAME_PRINT_QUEUE,
	FRAME_HELP,
	FRAME_MAIN_MENU

}FRAME_MENU_CHOICE;

//structs
typedef struct HEADER
{
	BYTE bReceiverAddr;			//receiver ID. 0xFF = broadcast
	BYTE bSenderAddr;			//sender ID
	BYTE bVersion;				//must be 1 for version 1
	long lDataLength;			//size of message
	char cSettings[2];			//settings[0]: 0 for no compression, 1 for RLE, 2 for HUFFMAN, 3 for RLE and HUFFMAN
								//settings[1]: 0 for no encryption, 1 for XOR encryption
	unsigned short sPriority;	//controls priority of message
}HEADER;

typedef struct FRAME
{
	HEADER header;
	char message[MAX_QUOTE_LENGTH + 1];
}FRAME;

//prototypes
int frameMenu(void);				//manages frame menu (Echo_Frame.cpp)
int frameSendText(void);			//wrapper for sending a message with a frame (Echo_Frame.cpp)
int frameSendQuote(void);			//wrapper for sending quotes (Echo_Frame.cpp)
int frameSendMultiple(void);		//wrapper for sending multiple texts (Echo_Frame.cpp)
int frameReceiveText(void);			//wrapper for receiving text (Echo_Frame.cpp)
int frameReceiveMultipleText(void);	//wrapper for receiving multiple texts (Echo_Frame.cpp)
int framePrintQueue(void);			//wrapper for printing contents of queue (Echo_Frame.cpp)

#endif