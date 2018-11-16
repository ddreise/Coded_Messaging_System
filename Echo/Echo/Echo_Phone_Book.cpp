/* 	Echo_Phone_Book.cpp
*	Implementation to handle phone book of Echo
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

#include "Echo_Phone_Book.h"
#include "Echo_Error.h"
#include "Echo_Input.h"
#include <stdio.h>
#include <Windows.h>

//functions

//manages menu of phone book
int phoneBookMenu(void)
{
	PHONE_BOOK_MENU_CHOICE choice;

	while (true)
	{
		printf("\nPhone Book\n");

		printf("\nWhat would you like to do?\n"
			"1 - Search (NOT IMPLEMENTED)\n"
			"2 - Add to Phone Book (NOT IMPLEMENTED)\n"
			"3 - Remove from Phone Book (NOT IMPLEMENTED)\n"
			"4 - Help (NOT IMPLEMENTED)\n"
			"5 - Main Menu\n");
		choice = (PHONE_BOOK_MENU_CHOICE)getMenuChoice();
		system("CLS");

		switch (choice)
		{
		case PHONE_BOOK_SEARCH:
			//error(phoneBookSearch);
			break;
			
		case PHONE_BOOK_ADD:
			//error(phoneBookAdd);
			break;

		case PHONE_BOOK_REMOVE:
			//error(phoneBookRemove);
			break;

		case PHONE_BOOK_HELP:
			//help();
			break;

		case PHONE_BOOK_MAIN_MENU:
			return SUCCESS;
			break;

		case PHONE_BOOK_FAIL:
		default:
			printf("\nThat is an incorrect option. You're a loser. Try again :)\n");
			break;
		}
	}
}