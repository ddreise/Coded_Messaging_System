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
	SEND_MESSAGE = 1,
	RECEIVE_MESSAGE,
	PHONE_BOOK,
	FRAME,
	MAIN_MENU_HELP,
	EXIT
} MENU_CHOICE;

//enum for error types
enum ERROR_CODES		///PUT THIS INTO SEPARATE FILE, BIG ERROR FILE
{
	SUCCESS,
	INIT_ERROR,
	MENU_ERROR,
	EXIT_ERROR
};

//prototypes
int startInit(void);				//handles initial communication requirements (COM, sender id, etc)
int mainMenu(void);					//handles main menu screen of Echo
int exit(void);						//exits Echo (releases necessary info, end of program management)
void mainError(int(*func)(void));	//will handle any errors passed from other functions

#endif

