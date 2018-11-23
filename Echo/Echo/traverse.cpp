/* 	traverse.cpp - Implementation of traverse to execute something on multiple nodes in a list
 *  Assignment 2 - Recursion
 *  ESE 3: Data Structures and Algorithms
 *  By: Justin Turcotte
 * 		Michael Galle
 *  18/10/16
 */

#include <stdio.h>
#include <stdlib.h>
#include "traverse.h"
#include "queue.h"

//calls visit on each node in the list in forward order
void traverse(Link startNode, void (*visit) (Link))
{
    //check for a valid node
    if(startNode == NULL) return;
    
    (*visit) (startNode); //calls visit before recursive call so we go forward
    traverse(startNode->pNext, visit);
}

//calls visit on each node in the list in reverse order
void traverseR(Link endNode, void (*visit) (Link))
{
    //check for a valid node
    if(endNode == NULL) return;

    traverseR(endNode->pNext, visit);
    (*visit) (endNode); //calls visit after recursive call so we go in backwards order
}

//counts number of nodes in queue
int countNodes(Link startNode)
{
	//check for valid node
	if (startNode == NULL) return 0;

	return 1 + countNodes(startNode->pNext);
}

void printMessage(Link node)
{
	printf("\nMESSAGE DETAILS:\n"
		"Receiver Address:	0x%x\n"
		"Version:			%d\n"
		"Data Length:		%ld\n"
		"MESSAGE:\n"
		"%s"
		"\n",
		node->data.header.bReceiverAddr, node->data.header.bVersion, node->data.header.lDataLength, node->data.message);
}