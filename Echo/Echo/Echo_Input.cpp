/* 	Echo_Input.h
 *	Implementation to handle user input from Echo
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

#define _CRT_SECURE_NO_WARNINGS

#include "Echo_Input.h"
#include "Echo_Error.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//functions

//will get a line of input from user and put it into buff
int getMenuChoice(void)
{
	int i = 0;							//disposable
	char buff[MAX_BUFFER_SIZE];
	int choice = 0;

	//get input from user
	fgets(buff, MAX_BUFFER_SIZE, stdin);

	//put '\n' at the first space or ignore if '\n' is found first
	for (i = 0; i < MAX_BUFFER_SIZE; i++)
	{
		if (buff[i] == ' ')
		{
			buff[i] = '\0';
			break;
		}
	}

	//convert input to an int
	choice = atoi(buff);

	//return the input
	return choice;
}