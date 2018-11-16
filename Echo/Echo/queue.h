/* 	queue.h - Declaration of queue to hold prototypes that allow linking and multiple quotes
 *  Assignment 1 - Queues (PART 2)
 *  ESE 3: Data Structures and Algorithms
 *  By: Justin Turcotte
 * 		Michael Galle
 *  18/10/16
 */

#ifndef QUEUE_H
#define QUEUE_H

#define MESSAGE_SIZE 140

#include "message.h"	//neccessary for item part of node

typedef struct node Node; //typedef it as a user friendly word like Node
typedef Node* Link; //link will be a pointer to the next node

//Structure for a linked list which will have data and a pointer to the next struct
struct node
{
    Item Data;
    Link pNext;
};

void InitQueue(void);       //Initialize queue
void ReleaseQueue(void);     //Releases the queue and frees memory
int IsQueueEmpty(void);     //Check if queue is empty (0 - false, not empty, 1 - true, is empty)
void EnQueue(Link Data);    //Add to the queue ('push')
Link DeQueue(void);         //Remove from the queue ('pop')
Link AccessQueue(void);     //simple function to access queue without popping or pushing

#endif //QUEUE_H

