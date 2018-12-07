/* 	Echo_Receive_Message.h
*	Interface to handle receiving messages
*
*  Coded Messaging System - Echo
*  ESE 3: Engineering Projects III
*
*  By: Justin Turcotte
* 		Daniel Dreise
*		Ramtin Alikhani
*
*  Thursday, November 05, 2018
*/

#ifndef ECHO_RECEIVE_MESSAGE
#define ECHO_RECEIVE_MESSAGE

//enum for menu choices
typedef enum RECEIVE_MENU_CHOICE
{
	RECEIVE_FAIL,
	RECEIVE_AUDIO,
	RECEIVE_TEXT,
	RECEIVE_MAIN_MENU
}RECEIVE_MENU_CHOICE;

//prototypes
int receiveMenu(void);	//displays receive menu
int receiveText(void);	//wrapper to receive text
int receiveAudio(void);	//wrapper to receive audio

#endif