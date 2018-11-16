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

void printMessage(Link node)
{
    printf("%s\n", node->Data.message);
}