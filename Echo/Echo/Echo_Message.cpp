/* 	Echo_Message.h
 *	Implementation to handle message menu of Echo
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

#include "Echo_Message.h"
#include "Echo_Error.h"
#include "Echo_Input.h"
#include <stdio.h>
#include <Windows.h>

//functions

//sending menu
int sendMenu(void)
{
	SEND_MENU_CHOICE choice;

	while (true)
	{
		printf("\nSend Message\n");

		printf("\nWhat would you like to do?\n"
			"1 - Send Audio (NOT IMPLEMENTED)\n"
			"2 - Send Text (NOT IMPLEMENTED)\n"
			"3 - Help (NOT IMPLEMENTED)\n"
			"4 - Main Menu\n");
		choice = (SEND_MENU_CHOICE)getMenuChoice();
		system("CLS");

		switch (choice)
		{
		case SEND_AUDIO:
			break;

		case SEND_TEXT:
			break;

		case SEND_MENU_HELP:
			break;

		case MAIN_MENU:
			return SUCCESS;
			break;

		case SEND_FAIL:
		default:
			printf("\nThat is an incorrect option. Try again :)\n");
			break;
		}
	}
}