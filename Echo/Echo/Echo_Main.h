/* 	Echo_Main.h
 *	Interface to handle high level main functions of Echo
 *
 *  Coded Messaging System - Echo
 *  ESE 3: Engineering Projects III
 *
 *  By: Justin Turcotte
 * 		Daniel Dreise
 *		Ramtin Alikhani
 *
 *  Thursday, November 03, 2018
 */

#ifndef ECHO_MAIN_H
#define ECHO_MAIN_H

//enum for menu choices
typedef enum MAIN_MENU_CHOICE
{
	MAIN_FAIL,
	MAIN_SEND_MESSAGE,
	MAIN_RECEIVE_MESSAGE,
	MAIN_PHONE_BOOK,
	MAIN_FRAME,
	MAIN_MENU_HELP,
	EXIT
} MENU_CHOICE;

//prototypes
int startInit(void);				//handles initial communication requirements (COM, sender id, etc)
int mainMenu(void);					//handles main menu screen of Echo
int exit(void);						//exits Echo (releases necessary info, end of program management)
char* getSenderID(void);			//returns the sender ID

#endif

