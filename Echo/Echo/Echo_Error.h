/* 	Echo_Error.h
 *	Interface to handle message errors returned from functions
 *
 *  Coded Messaging System - Echo
 *  ESE 3: Engineering Projects III
 *
 *  By: Justin Turcotte
 * 		Daniel Dreise
 *		Ramtin Alikhani
 *
 *  Thursday, November 4, 2018
 */

#ifndef ECHO_ERROR_H
#define ECHO_ERROR_H

//enum for error codes
typedef enum ERROR_CODES
{
	SUCCESS,
	MAIN_INIT_ERR,
	MAIN_MENU_ERR,
	MAIN_EXIT_ERR,
	SEND_MENU_ERR

}ECHO_ERRORS;

//prototypes
void error(int(*func)(void));	//will handle error results from functions

#endif