/* 	Echo_Phone_Book.cpp
*	Implementation to handle phone book of Echo
*
*  Coded Messaging System - Echo
*  ESE 3: Engineering Projects III
*
*  By: Justin Turcotte
* 		Daniel Dreise
*		Ramtin Alikhani
*
*  Thursday, November 05, 2018
*/

#include "Echo_Phone_Book.h"
#include "Echo_Error.h"
#include "Echo_Input.h"
#include <stdio.h>
#include <Windows.h>


/*** Variables ***/
static ID NullItem = {};      // children of leaf nodes
static tlink head;               // 'head' points to root (private variable)


/*** Function Implemenations ***/

//manages menu of phone book
int phoneBookMenu(void)
{
	PHONE_BOOK_MENU_CHOICE choice;

	while (true)
	{
		printf("\nPhone Book\n");

		printf("\nWhat would you like to do?\n"
			"1 - Print phonebook\n"
			"2 - Main Menu\n");
		choice = (PHONE_BOOK_MENU_CHOICE)getMenuChoice();
		system("CLS");

		switch (choice)
		{
		case PHONE_BOOK_PRINT:
			BSTPrint(getHead());

		case PHONE_BOOK_MAIN_MENU:
			return SUCCESS;
			break;

		case PHONE_BOOK_FAIL:
		default:
			printf("\nThat is an incorrect option. You're a loser. Try again :)\n");
			break;
		}
	}
}

void phoneBookSearch() {

}


// creates a new tree node using malloc()
tlink newTreeNode(ID item, tlink left, tlink right) {
	tlink pNew = (tlink)malloc(sizeof(*pNew));
	pNew->item = item;
	pNew->pLeft = left;
	pNew->pRight = right;

	return(pNew);
}


// creates an empty Binary Search Tree
void BSTInit(void) {
	head = NULL;
}


// Search for a key in the BST (using message in struct Item)
ID BSTSearch(tlink h, char *searchKey) {
	int rc;
	int i = 0;

	if (h == NULL) return (NullItem);     // go to end & not found

	if (searchKey[i] == h->item.address[i]) {
		if (searchKey[i + 1] == h->item.address[i + 1]) {
			return (h->item);			// found it
		}
	}

	if (searchKey[i] < h->item.address[i]) {
		return (BSTSearch(h->pLeft, searchKey));
	}
	else {
		return (BSTSearch(h->pRight, searchKey));
	}

	//rc = strcmp(szSearchKey, h->msg.key);

	// if (rc == 0) {
	// 	//printf("BSTSearch: rc == 0\n\n"); 
	// 	return (h->msg);       // found it
	// }
	// if (rc < 0) {
	// 	//printf("BSTSearch: rc < 0\n\n");	
	// 	return (BSTSearch(h->pLeft, szSearchKey));
	// }
	// else {
	// 	//printf("BSTSearch: rc > 0\n\n");
	// 	return (BSTSearch(h->pRight, szSearchKey));
	// }			
}

ID Search(char* searchKey) {
	return(BSTSearch(head, searchKey));
}


// Insert a key in the BST (uses szKey as before)
tlink BSTInsert(tlink h, ID item) {
	int rc;

	if (h == NULL) {
	//	printf("BSTInsert: treenode is empty(NULL)\n\n");
		return(newTreeNode(item, NULL, NULL));     // insert pt
	}

	rc = strcmp(item.address, h->item.address);        // go left or right?

	if (rc < 0) {
		//printf("BSTInsert: rc < 0 ---> go left\n\n");
		h->pLeft = BSTInsert(h->pLeft, item);
	}
	else {
		//printf("BSTInsert: rc > or = 0 ---> go right\n\n");
		h->pRight = BSTInsert(h->pRight, item);
	}
	return(h);      // pointer to (new/existing) child
}   // passed up to parent             


	// Insert data by calling BSTInsert
void Insert(ID item) {
	head = BSTInsert(head, item);
	//printf("Success in inserting new node with message\n\n"); 	// TEST
}

void BSTPrint(tlink h) {
	if (h == NULL) {						// reached leaf
											//printf("BSTPrint: NULL\n\n");
		return;
	}
	else {
		//printf("BSTPrint: not NULL\n\n");

		BSTPrint(h->pLeft);						// left
		printf("Address: %s\n", h->item.address);	// center
		BSTPrint(h->pRight);					// right
	}
	return;
}

// count the number of nodes in the tree
int countNodes(tlink h) {
	int numNodes = 1;				// set at 1 to count head

	if (h == NULL) {
		return 0;
	}
	else {
		numNodes += countNodes(h->pLeft);		// numNodes = numNodes + countnodes(h->pLeft)
		numNodes += countNodes(h->pRight);		// numNodes = numNodes + countnodes(h->pLeft)
	}
	return numNodes;
}

// get the head of the Binary Search Tree
tlink getHead() {
	return head;
}

// get the height of the Binary Search Tree
int getHeight(tlink h) {

	if (h == NULL) {
		return -1;			// start at -1 so as to not account the head of the tree.
	}

	int leftH = getHeight(h->pLeft);			// recursion
	int rightH = getHeight(h->pRight);

	if (leftH > rightH) {
		return (leftH + 1);
	}
	else {
		return (rightH + 1);
	}
}

//// defines the search key
//link defineSearchKey(link h) {
//
//	int hashNum;
//
//	hashNum = hashU((char*)h, HASH_SIZE);
//	printf("%d", hashNum);
//
//	// int j = 0, k = 0;
//
//	// for (k = 0; k < 5; k++){
//	// 	if (h->msg.message[0] != '"'){
//	// 		if (h->msg.message[1] != '"' || ' '){
//	// 			h->msg.key[j] = h->msg.message[j];
//	// 			//searchKey[j] = buff->msg.key[j];
//	// 			j++;
//	// 		}
//	// 		else{
//	// 			h->msg.key[j] = h->msg.message[j+2];
//	// 			j++;}
//
//	// 	}
//	// 	else{
//	// 		h->msg.key[j] = h->msg.message[j+1];
//	// 		//searchKey[j] = buff->msg.key[j];
//	// 		j++;
//	// 	}
//	// }
//
//	return h;
//}




