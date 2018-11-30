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
#include "message.h"	//need quote program to use quotes
#include "queue.h"		//need fifo queue program to use fifo queue
#include "traverse.h"	//need traverse program to go thorugh queue
#include "RS232Comm.h"
#include "Echo_Main.h"
#include "Echo_Message.h"
#include <stdio.h>
#include <Windows.h>
#include <malloc.h>
#include <time.h>

//Static Variables
static Link* priorityQueue;	//used to hold the priority of the 

//functions

//manages frame menu
int frameMenu(void)
{
	FRAME_MENU_CHOICE choice;

	while (true)
	{
		printf("\nFrame\n");

		printf("\nWhat would you like to do?\n"
			"1 - Send a text message\n"
			"2 - Send a random quote (NOT IMPLEMENTED)\n"
			"3 - Send multiple texts\n"
			"4 - Receive a text message (NOT IMPLMENTED)\n"
			"5 - Receive multiple texts\n"
			"6 - Print Messages in Queue\n"
			"7 - Help (NOT IMPLEMENTED)\n"
			"8 - Main Menu\n");
		choice = (FRAME_MENU_CHOICE)getMenuChoice();
		system("CLS");

		switch(choice)
		{
		case FRAME_SEND_TEXT_MESSAGE:
			error(frameSendText);
			break;

		case FRAME_SEND_RANDOM_QUOTE:
			error(frameSendQuote);
			break;
		
		case FRAME_SEND_MULTIPLE_TEXT:
			error(frameSendMultiple);
			break;

		case FRAME_RECEIVE_TEXT_MESSAGE:
			error(frameReceiveText);
			system("PAUSE");
			system("CLS");
			break;
			
		case FRAME_RECEIVE_MULTIPLE_TEXT:
			error(frameReceiveMultipleText);
			break;

		case FRAME_PRINT_QUEUE:
			error(framePrintQueue);
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

//wrapper for sending a message with a frame (Echo_Frame.cpp)
int frameSendText(void)
{
	//MUSTS:
	//	- get text the user wants to send
	//	- get senderId they want to send it to
	//	- transmit the message as frame
	//COULDS:
	//	- transmit messages over max buffer in 'frames'

	//variables
	int i;
	
	Link data;	//holds data to transmit

	//allocate space for data
	data = (Link)calloc(1, sizeof(*data));
	if (data == NULL)
	{
		printf("\nMEMORY ERROR: Unable to allocate space for data!\n");
		return -2;
	}

	for (i = 0; i < MAX_QUOTE_LENGTH + 1; i++) data->data.message[i] = 0;	//clear message to 0's

	printf("\nWhat is the priority of the message? ");																//get priority of the message
	data->data.header.sPriority = (short)getMenuChoice();

	printf("\nType the message you want to send: \n");
	fgets(data->data.message, MAX_QUOTE_LENGTH, stdin);
	system("CLS");

	//set header
	data->data.header.bReceiverAddr = 0xFF;
	data->data.header.bVersion = 1;

	//set size of message
	data->data.header.lDataLength = strlen(data->data.message);

	outputToPort(data, sizeof(*data));	//output to the port

	printf("\nMESSAGE DETAILS:\n"
		"Receiver Address:	0x%x\n"
		"Version:			%d\n"
		"Data Length:		%ld\n"
		"Priority:			%d\n"
		"MESSAGE:\n"
		"%s"
		"\n",
		data->data.header.bReceiverAddr, data->data.header.bVersion, data->data.header.lDataLength, data->data.header.sPriority, data->data.message);

	system("PAUSE");

	system("CLS");
	return SUCCESS;
}

//wrapper for sending quotes (Echo_Frame.cpp)
int frameSendQuote(void)
{
	//MUST:
	//	- send a random quote form a txt file
	//	- send quote as a node
	//COULD:
	//	- queue messages for sending
	//	- send multiple quotes if desired

	//seed random number generator
	srand(time(NULL));

	Link data;					//holds quote data
	int randNum;				//holds random number for quote selection
	int numQuotes;				//holds number of quotes
	long int* indiceQuotes;		//holds indices for quotes
	int* lengthQuotes;			//holds length for quotes

	//set up for message sending
	numQuotes = fnumQuotes();
	indiceQuotes = fquoteIndices(numQuotes);
	lengthQuotes = fquoteLength(numQuotes, indiceQuotes);
	randNum = frandNum(0, numQuotes);
	data = (Link)calloc(1, sizeof(*data));	//allocate space for data
	if (data == NULL)
	{
		printf("\nMEMORY ERROR: Failed to allocate data for quote!\n");
		return -2;
	}

	//get random quote
	GetMessageFromFile(data->data.message, randNum, numQuotes, indiceQuotes, lengthQuotes);

	//set header
	data->data.header.bReceiverAddr = 0xFF;
	data->data.header.bVersion = 1;

	//set size of message
	data->data.header.lDataLength = strlen(data->data.message);

	//confirm user is ready to send random quote
	printf("\nPress a key to send a random quote\n");
	getchar();

	//send a random quote
	outputToPort(data, sizeof(*data));

	//go back to previous menu
	getchar();
	free(data);		//free memory used for data
	system("CLS");
	return SUCCESS;

}

//wrapper for sending multiple texts (Echo_Frame.cpp)
int frameSendMultiple(void)
{
	//send multiple texts or quotes
	int i;
	int quotes = 0, texts = 0;	//hold how many messages and/or random quotes

	printf("How many texts would you like to send?\n");
	scanf_s("%d", &texts);
	getchar();

	printf("\nHow many quotes would you like to send?\n");
	scanf_s("%d", &quotes);
	getchar();

	for (i = 0; i < texts; i++)
	{
		error(frameSendText);
	}

	for (i = 0; i < quotes; i++)
	{
		error(frameSendQuote);
	}

	return SUCCESS;
}

//wrapper for receiving text (Echo_Frame.cpp)
int frameReceiveText(void)
{
	//MUSTS:
	//	- receive text on comport via frame
	//COULDS:
	//	- log messages in a .txt

	int i;	//disposable
	Link data;

	//allocate space for data
	data = (Link)calloc(1, sizeof(*data));
	if (data == NULL)
	{
		printf("\nMEMORY ERROR: Unable to allocate space for data!\n");
		return -2;
	}

	//receive the message
	inputFromPort(data, sizeof(*data));

	printf("\nMessage Received!\n"
		"MESSAGE DETAILS:\n"
		"Receiver Address:	0x%x\n"
		"Version:			%d\n"
		"Data Length:		%ld\n"
		"MESSAGE:\n"
		"%s"
		"\n",
		data->data.header.bReceiverAddr, data->data.header.bVersion, data->data.header.lDataLength, data->data.message);

	//store message in queue
	if (IsQueueEmpty()) InitQueue();

	EnQueue(data);
	printf("\nMESSAGE STORED IN QUEUE!\n");
	printf("\nTHERE ARE %d MESSAGES IN QUEUE\n", countNodes(AccessQueue()));

	return SUCCESS;
}

int frameReceiveMultipleText(void)
{
	int i;
	int count = 0;

	printf("\nPlease enter how many messages you are expecting\n");
	scanf_s("%d", &count);
	getchar();

	for(i = 0; i < count; i++)
	{
		error(frameReceiveText);
	}

	printf("\nFinished Receiving!\n");

	system("PAUSE");
	system("CLS");
	return SUCCESS;
}

//wrapper for printing contents of queue (Echo_Frame.cpp)
int framePrintQueue(void)
{
	//print contents of queue
	printf("\nPRINTING QUEUE OLDEST TO NEWEST:\n");

	traverse(AccessQueue(), printMessage);

	system("PAUSE");
	system("CLS");
	return SUCCESS;
}