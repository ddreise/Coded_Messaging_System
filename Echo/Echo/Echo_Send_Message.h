/* 	Echo_Send_Message.h
 *	Interface to handle message menu of Echo
 *
 *  Coded Messaging System - Echo
 *  ESE 3: Engineering Projects III
 *
 *  By: Justin Turcotte
 * 		Daniel Dreise
 *		Ramtin Alikhani
 *
 *  Thursday, November 3, 2018
 */

#ifndef ECHO_SEND_MESSAGE_H
#define ECHO_SEND_MESSAGE_H

typedef enum SEND_MENU_CHOICE
{
	SEND_FAIL,
	SEND_AUDIO,
	SEND_TEXT,
	SEND_MAIN_MENU
} SEND_MENU_CHOICE;

//prototypes

//functions to access static variables
void setComPort(char* _comPort);
char* getComPort(void);
void setSenderId(char* _senderId);
char* getSenderId(void);

int sendMenu(void);					//sending menu
int sendText(void);					//wrapper to begin sending text
int sendAudio(void);				//wrapper to send audio

#endif