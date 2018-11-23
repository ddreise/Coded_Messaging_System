/* 	traverse.h - Declaration of traverse to hold prototypes that allow executing something on multiple nodes in a list
 *  Assignment 2 - Recursion
 *  ESE 3: Data Structures and Algorithms
 *  By: Justin Turcotte
 * 		Michael Galle
 *  18/10/16
 */

#ifndef TRAVERSE_H
#define TRAVERSE_H

#include "queue.h"

void traverse(Link startNode, void (*visit) (Link));		//calls visit on each node in a list in forward order
void traverseR(Link startNode, void (*visit) (Link));		//calls visit on each node in a list in reverse order
int countNodes(Link startNode);								//counts number of nodes in queue

void printMessage(Link node);                            //prints the message of the desired node
#endif