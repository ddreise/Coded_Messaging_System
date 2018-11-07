/* 	Echo_Receive_Message.cpp
*	Implementation to handle the menu for receiving messages
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

#include "Echo_Receive_Message.h"
#include "Echo_Error.h"
#include "Echo_Input.h"
#include "Echo_Send_Message.h"
#include "RS232Comm.h"
#include <stdio.h>
#include <Windows.h>

//important variables
char inBuff[MAX_BUFFER_SIZE];

//functions

//displays receive menu
int receiveMenu(void)
{
	RECEIVE_MENU_CHOICE choice;

	while (true)
	{
		printf("\nReceive Message\n");

		printf("\nWhat would you like to do?\n"
			"1 - Receive Audio (NOT IMPLEMENTED)\n"
			"2 - Receive Text\n"
			"3 - Help (NOT IMPLEMENTED)\n"
			"4 - Main Menu\n");
		choice = (RECEIVE_MENU_CHOICE)getMenuChoice();
		system("CLS");

		switch (choice)
		{
		case RECEIVE_AUDIO:
			//error(receiveAudio);
			break;

		case RECEIVE_TEXT:
			error(receiveText);
			break;

		case RECEIVE_MENU_HELP:
			//help();
			break;

		case RECEIVE_MAIN_MENU:
			return SUCCESS;
			break;

		case RECEIVE_FAIL:
		default:
			printf("\nThat is an incorrect option. You're a loser. Try again :)\n");
			break;
		}
	}
}

//wrapper to receive text
int receiveText(void)
{
	//MUSTS:
	//	- receive text on comport
	//	- get receiveId of message sent
	//COULDS:
	//	- log messages in a .txt

	int i;	//disposable

	//receive the message
	inputFromPort(inBuff, MAX_BUFFER_SIZE);

	printf("\nMessage Received:\n");
	printf("%s\n", inBuff);

	system("PAUSE");

	//clear the inBuff
	for (i = 0; i < strlen(inBuff); i++)
	{
		inBuff[i] = 0;
	}

	system("CLS");
	return SUCCESS;
}