/* 	Echo_Phone_Book.h
*	Interface to handle phone book of Echo
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

#ifndef ECHO_PHONE_BOOK_H
#define ECHO_PHONE_BOOK_H

//enum for menu choices
typedef enum PHONE_BOOK_MENU_CHOICE
{
	PHONE_BOOK_FAIL,
	PHONE_BOOK_SEARCH,
	PHONE_BOOK_ADD,
	PHONE_BOOK_REMOVE,
	PHONE_BOOK_HELP,
	PHONE_BOOK_MAIN_MENU

}PHONE_BOOK_MENU_CHOICE;

//prototypes
int phoneBookMenu(void);	//manages menu of phone book

#endif