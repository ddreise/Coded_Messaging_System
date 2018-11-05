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
	SEND_MENU_HELP,
	MAIN_MENU
} SEND_MENU_CHOICE;

//prototypes
int sendMenu(void);					//sending menu

#endif