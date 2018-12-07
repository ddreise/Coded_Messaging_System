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