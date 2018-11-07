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

#include "Echo_Send_Message.h"
#include "Echo_Error.h"
#include "Echo_Input.h"
#include "RS232Comm.h"
#include <stdio.h>
#include <Windows.h>

//important variables
static char comPort[COM_LENGTH];
static char senderId[MAX_ID_LENGTH];
static char outBuff[MAX_BUFFER_SIZE];

//functions

//functions to access static variables
void setComPort(char* _comPort)
{
	strcpy_s(comPort, _comPort);
}

char* getComPort(void)
{
	return comPort;
}

void setSenderId(char* _senderId)
{
	strcpy_s(senderId, _senderId);
}

char* getSenderId(void)
{
	return senderId;
}

//sending menu
int sendMenu(void)
{
	SEND_MENU_CHOICE choice;

	while (true)
	{
		printf("\nSend Message\n");

		printf("\nWhat would you like to do?\n"
			"1 - Send Audio (NOT IMPLEMENTED)\n"
			"2 - Send Text\n"
			"3 - Help (NOT IMPLEMENTED)\n"
			"4 - Main Menu\n");
		choice = (SEND_MENU_CHOICE)getMenuChoice();
		system("CLS");

		switch (choice)
		{
		case SEND_AUDIO:
			//error(sendAudio);
			break;

		case SEND_TEXT:
			error(sendText);
			break;

		case SEND_MENU_HELP:
			//sendHelp();
			break;

		case SEND_MAIN_MENU:
			return SUCCESS;
			break;

		case SEND_FAIL:
		default:
			printf("\nThat is an incorrect option. You're a loser. Try again :)\n");
			break;
		}
	}
}

//wrapper to begin sending text
int sendText(void)
{
	//MUSTS:
	//	- get text the user wants to send
	//	- get senderId they want to send it to
	//	- transmit the message
	//COULDS:
	//	- transmit messages over max buffer in 'frames'
	
	printf("\nType the message you want to send: \n");
	fgets(outBuff, MAX_BUFFER_SIZE, stdin);
	system("CLS");

	outputToPort(outBuff, strlen(outBuff));	//output to the port

	system("PAUSE");

	system("CLS");
	return SUCCESS;
}