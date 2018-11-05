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
*  Thursday, November 05, 2018
*/

#ifndef ECHO_FRAME_H
#define ECHO_FRAME_H

//enum for menu choices
typedef enum FRAME_MENU_CHOICE
{
	FRAME_FAIL,
	FRAME_SEND_RANDOM_QUOTE,
	FRAME_RECEIVE_RANDOM_QUOTE,
	FRAME_HELP,
	FRAME_MAIN_MENU

}FRAME_MENU_CHOICE;

//prototypes
int frameMenu(void);	//manages frame menu

#endif