/* message.cpp - Implementation: Functions for File IO - Getting random messages from a file
 *  Assignment 1 - Queues (PART 1)
 *  ESE 3: Data Structures and Algorithms
 *  By: Justin Turcotte
 * 		Michael Galle
 *  18/10/31
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>			// Dynamic memory allocation for arrays that store quote location and length
#include "message.h"

// Function gets a random number between min and max (max is the number of quotes in the file)
int frandNum(int min, int max) 
{
    int randNum =  (min + rand() % (max + 1 - min)); //create the random number

    return randNum;
}

// Function returns number of quotes in the file (only need to run once)
int fnumQuotes(void) 
{
    FILE* fp;
    char c;
    int counter = 0;

    //Test for valid file before doing anything
    if(fp = fopen("FortuneCookies.txt", "r"))
    {
        printf("SUCCESS: File opened!\n");

        //Read the file and increment everytime you encounter a new quote (defined by '%%')
        while ((c = fgetc(fp)) != EOF)
        {
            if(c == '%')
            {
                if(fgetc(fp) == '%')
                {
                    counter++;
                }
            }
        }

        fclose(fp);
        return (counter);
    }
    else 
    {
        printf("ERROR: Could not open file!\n");
        return (-1);
    }
}

// Function returns an array that indicates the start of every quote in the file (number of characters from the start of the file) 
long int* fquoteIndices(int numQuotes) 
{
    FILE* fp;
    char c;
    long int* pQuoteStart = 0; //pointer to hold beginning of the pointer array
    long int* pQuotePos = 0; //pointer used to jump through the pointer array to store locations
    
    //Allocate space needed to store all quote locations from start of file, return error if it fails
    if( (pQuoteStart = (long int*) calloc(numQuotes, sizeof(long int))) == NULL )
    {
        printf("ERROR: Failed to allocate storage to quote locations!\n");

        return ( (long int*) -2);
    }
    else
    {
        printf("SUCCESS: Space of [%d] allocated to quote storage locations!\n", numQuotes*sizeof(pQuoteStart));

        //Test for valid file
        if(fp = fopen("FortuneCookies.txt", "r"))
        {
            printf("SUCCESS: File opened!\n");

            pQuotePos = pQuoteStart; //Initialize pQuotePos to pQuoteStart

            //Find beginning of quotes and save location in pQuoteStart array
            while((c = fgetc(fp)) != EOF)
            {
                //steps++; //increments steps to keep track of location
                if(c == '%')
                {
                    if( (c = fgetc(fp)) == '%')
                    {
                        //Save the location of the quote, increment the pointer for the next quote
                        *pQuotePos = ftell(fp);
                        pQuotePos++;
                    }
                }
            }

            printf("SUCCESS: Quote locations assigned!\n"); //FOR DEBUGGING

            pQuotePos = 0; //free pQuotePos            
            return pQuoteStart;
        }
        else
        {
            printf("ERROR: Could not open file!\n");
            return ( (long int*) -1);
        }
    }
}

// Function returns the smaller of the actual quote length or MAX_QUOTE_LENGTH
int* fquoteLength(int numQuotes, long int* quoteIndices) 
{
    FILE* fp;
    char c;
    int* pQuoteStart = 0; //pointer to hold beginning of the pointer array
    int* pQuotePos = 0; //pointer used to jump through the pointer array to store locations
    int length; //store the length of the quotes

    int i = 0; //disposable variable

    //Test the file for validity
    if(fp = fopen("FortuneCookies.txt", "r"))
    {
        printf("SUCCESS: File opened!\n");

        //Attempt to allocate storage for quote lengths
        if( (pQuoteStart = (int*) malloc(numQuotes*sizeof(int*))) == NULL)
        {
             printf("ERROR: Failed to allocate storage to quote locations!\n");
            return ( (int*) -2);
        }
        else
        {
            printf("SUCCESS: Space of [%d] allocated to quote storage lengths!\n", numQuotes*sizeof(pQuoteStart));

            pQuotePos = pQuoteStart; //Initialize pQuotePos to pQuoteStart

            //Use quote indices and find lengths of each quote
            for(i = 0; i < numQuotes; i++)
            {
                //goto quote
                fseek(fp, quoteIndices[i], SEEK_SET);

                //find length of quote
                *pQuotePos = MAX_QUOTE_LENGTH-1; //-1 because there is going to be a null terminator appended later on so max quote is 139 chars
                for(length = 0; length < (MAX_QUOTE_LENGTH - 1); length++)
                {
                    if( (c = fgetc(fp)) == '%')
                    {
                        if( (c = fgetc(fp)) == '%')
                        {
                            *pQuotePos = length;
                            break;
                        }
                    } 
                }
                pQuotePos++;
            }

            printf("SUCCESS: Quote lengths assigned!\n");
            return pQuoteStart;
        }
    }
    else
    {
        printf("ERROR: Could not open file!\n");
        return ( (int*) -1);
    }
} 

// Function that gets q random quote from the FortuneCookies file 
int GetMessageFromFile(char* buff, int randNum, int numQuotes, long int* quoteIndices, int* quoteLengths) 
{
    FILE* fp;
    char c;
    int* pQuoteStart = 0; //pointer to hold beginning of the pointer array
    int* pQuotePos = 0; //pointer used to jump through the pointer array to store locations
    int length; //store the length of the quotes

    if(fp = fopen("FortuneCookies.txt", "r"))
    {
        fseek(fp, quoteIndices[randNum], SEEK_SET);

        //read quote into buff
        for(length = 0; length < quoteLengths[randNum]; length++)
        {
            buff[length] = fgetc(fp);
        }

        buff[quoteLengths[randNum]] = '\0'; //strings in c end in a null terminator ('\0') so it needs to be appended to the end of the quote
        
        //printf("%s\n", buff);

        return (0);
    }
    else
    {
        printf("ERROR: File can not be opened!\n");
        return(-1);
    }
    
}

//get a key
 int getKey(char* buff)
{
	int i = 0;							//disposable
	char c;

	char tempBuff[INPUT_BUFFER];		//string for key input, size allows to limit number of characters later

	printf("\nPlease enter a (maximum) 24 character string as a key: \n");
	fgets(tempBuff, INPUT_BUFFER, stdin);
	tempBuff[MAX_KEY_LENGTH - 1] = '\0';

	for (i = 0; i < MAX_KEY_LENGTH; i++)
	{
		//insert the character
		buff[i] = tempBuff[i];

		//if at \0, stop inserting
		if (buff[i] == '\0') break;
	}

	return(0);
}