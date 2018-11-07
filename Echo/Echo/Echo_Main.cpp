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
#include "Echo_Receive_Message.h"
#include "Echo_Phone_Book.h"
#include "Echo_Frame.h"
#include "RS232Comm.h"

#include <Windows.h>
#include <stdio.h>
#include <string.h>

//functions

//handles initial communication requirements (COM, sender id, etc)
int startInit(void)
{
	//MUSTS:
	//	- get user id
	//	- get com port
	//COULDS:
	//	- save user input for next time and check for previous input when program starts

	char senderId[MAX_ID_LENGTH];
	char comPort[COM_LENGTH];

	//get user (sender) id
	printf("\nPlease enter a user id (this will be used as the sender id). Max of %d characters.\n", MAX_ID_LENGTH-1);
	fgets(senderId, MAX_ID_LENGTH, stdin);

	//get communication port
	printf("\nPlease enter the com port to be used for communications (INPUT AS SHOWN: \"COM#\").\n");
	fgets(comPort, COM_LENGTH, stdin);

	//save senderId and comport to static variables in Echo_Send_Message.h
	setComPort(comPort);
	setSenderId(senderId);

	//initialize (open) the port
	initPort(comPort);

	system("PAUSE");

	system("CLS");
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
				"2 - Receive Message\n"
				"3 - Phone Book\n"
				"4 - Frame\n"
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
			error(receiveMenu);
			break;

		case MAIN_PHONE_BOOK:
			error(phoneBookMenu);
			break;

		case MAIN_FRAME:
			error(frameMenu);
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