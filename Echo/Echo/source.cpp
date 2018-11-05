/* 	source.cpp - Execution for running Echo - audio recording and playback
 *  Coded Messaging System - Echo Audio
 *  ESE 3: Engineering Projects III
 *  By: Justin Turcotte
 * 		Daniel Dreise
 *		Ramtin Alikhani
 *  Thursday, October 18, 2018
 */

#include <stdio.h>
#include <windows.h>
#include "Echo_Main.h"
#include "Echo_Error.h"
int	main(int argc, char *argv[])
{
	//startup initialization
	error(startInit);

	//main menu -> handles the rest of Echo except for exit
	error(mainMenu);

	//exit Echo
	error(exit);


	//commsTest();

	////ECHO-AUDIO-V01//

	////VARIABLE DECLARATIONS//
	//char save;															//???
	//char replay;														//???
	//char c;																//used to flush extra input (???)
	//FILE *f;															//???

	//int iInput;															//stores user input for main menu
	//int bQuit = 0;														//bool to quit program, while 0, program won't quit. if 1, quit program

	////TEMPORARY WELCOME SCREEN//
	//printf("Welcome to Echo! Be warned, this is version 01. Echo has not even been born yet. Her capabilities consist of only "
	//	"audio recording and playback. You have been warned! (bugs may occur at any moment. Please be careful!)\n"
	//	"Press enter to continue...\n");
	//getchar(); //pause until user enters a key

	////loop to run code until quit requested
	//while (!bQuit)
	//{
	//	printf("Thanks for staying! Currently, Echo is capable of... (Press the number corresponding to the action you want)\n"
	//		"1) Audio Recording\n"
	//		"2) Audio Playback\n"
	//		"3) Exit\n");

	//	scanf("%d", &iInput);	//receive input from the user

	//	switch (iInput)			//check which selection the user picks
	//	{
	//	case 1:
	//		echoRecord();		//handles recording capabilities of Echo
	//		break;
	//	case 2:
	//		echoPlayback();		//handles playback capabilities of Echo
	//		break;
	//	case 3:
	//		printf("Thanks for using Echo! Exiting now!\n");
	//		bQuit = 1;
	//		break;
	//	default:
	//		printf("\nERROR: Please enter a valid choice!\n");
	//	}
	//}





	//// save audio recording  
	//printf("Would you like to save your audio recording? (y/n): ");
	//scanf("%c", &save);
	//while ((c = getchar()) != '\n' && c != EOF) {}								// Flush other input
	//if ((save == 'y') || (save == 'Y')) {
	//	/* Open input file */
	//	f = fopen("recording.dat", "wb");
	//	if (!f) {
	//		printf("unable to open %s\n", "recording.dat");
	//		return 0;
	//	}
	//	printf("Writing to sound file ...\n");
	//	fwrite(iBigBuf, sizeof(short), lBigBufSize, f);
	//	fclose(f);
	//}

	//// replay audio recording from file -- read and store in buffer, then use playback() to play it
	//printf("Would you like to replay the saved audio recording from the file? (y/n): ");
	//scanf("%c", &replay);
	//while ((c = getchar()) != '\n' && c != EOF) {}								// Flush other input
	//if ((replay == 'y') || (replay == 'Y')) {
	//	/* Open input file */
	//	f = fopen("recording.dat", "rb");
	//	if (!f) {
	//		printf("unable to open %s\n", "recording.dat");
	//		return 0;
	//	}
	//	printf("Reading from sound file ...\n");
	//	fread(iBigBufNew, sizeof(short), lBigBufSize, f);				// Record to new buffer iBigBufNew
	//	fclose(f);
	//}
	//InitializePlayback();
	//printf("\nPlaying recording from saved file ...\n");
	//PlayBuffer(iBigBufNew, lBigBufSize);
	//ClosePlayback();

	printf("\n");
	system("pause");
	return(0);
}