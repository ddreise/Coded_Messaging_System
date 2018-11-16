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
#include <stdio.h>
#include <Windows.h>
#include <malloc.h>
#include <time.h>

//important variables
static int FRAME_INIT = 0;	//controls if the frame has been initialized

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
			error(frameSendQuote);
			break;
		
		case FRAME_RECEIVE_RANDOM_QUOTE:
			error(frameReceiveQuote);
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
	data = (Link) malloc(sizeof(*data));	//allocate space for data

	//get random quote
	GetMessageFromFile(data->Data.message, randNum, numQuotes, indiceQuotes, lengthQuotes);

	//add sender ID to key
	strcpy_s(data->Data.key, getSenderID());

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

//wrapper for receiving quotes (Echo_Frame.cpp)
int frameReceiveQuote(void)
{
	//MUST:
	//	- receive a quote as a node
	//	- store quote in fifo queue for later use
	//COULD:
	//	- store received quotes in a txt file

	Link data = (Link)malloc(sizeof(*data));	//quote being received

	//confirm the user is ready to receive a random quote
	printf("\nPress a key when you're ready to receive a random quote\n");
	getchar();

	//receive a random quote
	inputFromPort(data, sizeof(*data));

	//store the quote in a FIFO queue
	if(!FRAME_INIT) //init the queue
	{
		InitQueue();
		FRAME_INIT = 1;
	}
	//enqueue
	EnQueue(data);

	//print the quote to the user
	printf("\n%s:\n", AccessQueue()->Data.key);
	printf("%s\n", AccessQueue()->Data.message);

	//inform the user the quote is available in the FIFO queue
	printf("\nThe received quote is now available in the FIFO queue!\n");
	getchar();

	//return to previous menu
	free(data);
	system("CLS");
	return SUCCESS;
}