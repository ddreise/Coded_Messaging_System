#pragma once

#include <Windows.h>    // Includes the functions for serial communication via RS232

// Prototype the functions to be used

int commsTest();
void initPort(char* comPort); 
void purgePort();
void outputToPort(LPCVOID buf, DWORD szBuf);
void inputFromPort(LPVOID buf, DWORD szBuf);

// Sub functions
void createPortFile(char* comPort);
static int SetComParms();