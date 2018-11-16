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

#include "Echo_Frame.h"
#include "Echo_Error.h"
#include "Echo_Input.h"
#include <stdio.h>
#include <Windows.h>

//functions

//manages frame menu
int frameMenu(void)
{
	FRAME_MENU_CHOICE choice;

	while (true)
	{
		printf("\nFrame\n");

		printf("\nWhat would you like to do?\n"
			"1 - Send a random quote (NOT IMPLEMENTED)\n"
			"2 - Receive a random quote (NOT IMPLMENTED)\n"
			"3 - Help (NOT IMPLEMENTED)\n"
			"4 - Main Menu\n");
		choice = (FRAME_MENU_CHOICE)getMenuChoice();
		system("CLS");

		switch(choice)
		{
		case FRAME_SEND_RANDOM_QUOTE:
			//error(sendRandomQuote);
			break;
		
		case FRAME_RECEIVE_RANDOM_QUOTE:
			//error(receiveRandomQuote);
			break;

		case FRAME_HELP:
			//frameHelp();
			break;
			
		case FRAME_MAIN_MENU:
			return SUCCESS;
			break;

		case FRAME_FAIL:
		default:
			printf("\nThat is an incorrect option. You're a loser. Try again :)\n");
			break;
		}
	}
}