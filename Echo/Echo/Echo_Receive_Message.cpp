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
#include "Echo_Message.h"
#include "Echo_Send_Message.h"
#include "Echo_Phone_Book.h"
#include "audio_handling.h"
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
			"1 - Receive Audio\n"
			"2 - Receive Text\n"
			"3 - Main Menu\n");
		choice = (RECEIVE_MENU_CHOICE)getMenuChoice();
		system("CLS");

		switch (choice)
		{
		case RECEIVE_AUDIO:
			error(receiveAudio);
			break;

		case RECEIVE_TEXT:
			error(receiveText);
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

//wrapper to receive audio
int receiveAudio(void)
{
	//MUSTS:
	//	- receive audio and audio size
	//	- play audio to user
	//COULD:
	//	- store audio for later

	long audioSize;		//size of audio
	short* audio;		//audio data
	int status = 0;		//status for receiving audio, 0 is no issue, 1 is issue

	audioSetup();	//temp

	//receive size of audio
	inputFromPort(&audioSize, sizeof(audioSize));

	//send 'ok' if space is allocated for audio
	audio = (short*)malloc(audioSize);
	if (audio == NULL)
	{
		printf("\nERROR: Unable to allocate space required for audio buffer!\n");
		status = 1;	//update status and send error
		outputToPort(&status, sizeof(status));
		return -1;	//temp
	}

	//save audio to buffer
	setAudio(audio);
	setAudioSize(audioSize);

	//output 'ok' for receiving
	outputToPort(&status, sizeof(status));
	
	//receive audio
	inputFromPort(audio, audioSize);

	//play audio
	audioPlayback();

	system("PAUSE");
	return SUCCESS;
}