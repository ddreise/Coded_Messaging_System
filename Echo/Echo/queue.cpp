/* 	queue.cpp - Implementation of queue to handle queue functionality
 *  Assignment 1 - Queues (PART 2)
 *  ESE 3: Data Structures and Algorithms
 *  By: Justin Turcotte
 * 		Michael Galle
 *  18/10/16
 */

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "Echo_Frame.h"

static Link pHead;
static Link pTail;

//Initialize queue by setting pHead and pTail to null
void InitQueue(void)
{
    pHead = pTail = NULL;
    printf("SUCCESS: Queue initialized!\n");
}

//Releases queue by freeing memory
void ReleaseQueue(void)
{
    while(IsQueueEmpty() == 0)
    {
            free(DeQueue());
    }

    if(IsQueueEmpty() == 1) printf("SUCCESS: Queue released!\n");
    else printf("ERROR: Queue could not be released!");
}

//Returns non-zero if the queue is not empty
int IsQueueEmpty(void)
{
    return(pHead == NULL); //true = 1, false = 0
}

//Add (push) to the end of the queue
void EnQueue(Link pn)
{
    //if the head is null, then the queue is empty so the head is the same as the tail
    if(pHead == NULL)
    {
        pHead = pTail = pn;
    }
    //else the tail will point to the new data being added to the queue
    else
    {
        pTail->pNext = pn;
    }
    
    pTail = pn; //pn is now the last in the queue
    pTail->pNext = NULL; //the last in the queue points to nothing
}

//Remove (pop) from the top of the queue
Link DeQueue(void)
{
    Link pTemp;

    if(pHead == NULL) return(NULL); //the queue is empty so nothing to pop
    else
    {
        pTemp = pHead; //set pTemp so that the item can be used
        pHead = pHead->pNext; //pop off the head
    }

    return(pTemp); //returns the item for use
}

Link AccessQueue(void)
{
    return(pHead);
}