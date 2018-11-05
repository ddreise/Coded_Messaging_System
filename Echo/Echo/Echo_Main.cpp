/* 	Echo_Main.cpp
 *	Implementation to handle high level main functions of Echo
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

//includes
#include "Echo_Main.h"
#include "Echo_Error.h"
#include "Echo_Input.h"
#include "Echo_Send_Message.h"
#include <Windows.h>
#include <stdio.h>
#include <string.h>

//functions

//handles initial communication requirements (COM, sender id, etc)
int startInit(void)
{
	//get user (sender) id

	//get communication port

	return SUCCESS;
}

//handles main menu screen of Echo
int mainMenu(void)
{
	MAIN_MENU_CHOICE choice;	//holds the menu choice of user

	while (true)
	{
		printf("\nMain Menu\n");

		printf("\nWhat would you like to do?\n"
				"1 - Send Message\n"
				"2 - Receive Message (NOT IMPLEMENTED)\n"
				"3 - Phone Book (NOT IMPLEMENTED)\n"
				"4 - Frame (NOT IMPLEMENTED)\n"
				"5 - Help (NOT IMPLEMENTED)\n"
				"6 - Exit\n");
		choice = (MAIN_MENU_CHOICE)getMenuChoice();
		system("CLS");

		switch (choice)
		{
		case MAIN_SEND_MESSAGE:
			error(sendMenu);
			break;

		case MAIN_RECEIVE_MESSAGE:
			//error(receiveMenu);
			break;

		case MAIN_PHONE_BOOK:
			//error(phoneBook);
			break;

		case MAIN_FRAME:
			//error(frame);
			break;

		case MAIN_MENU_HELP:
			//error(mainHelp);
			break;

		case EXIT:
			printf("\nExitting now...\n");
			return SUCCESS;	//exits the program with no error
			break;
		
		case MAIN_FAIL:
		default:
			printf("\nThat is an incorrect option. You're a loser. Try again :)\n");
			break;
		}
	}
}

//exits Echo (releases necessary info, end of program management)
int exit(void)
{

	return SUCCESS;
}