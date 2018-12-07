/* 	Echo_Phone_Book.h
*	Interface to handle phone book of Echo
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

#ifndef ECHO_PHONE_BOOK_H
#define ECHO_PHONE_BOOK_H

#define ADDRESS_LENGTH 10

//enum for menu choices
typedef enum PHONE_BOOK_MENU_CHOICE
{
	PHONE_BOOK_FAIL,
	PHONE_BOOK_PRINT,
	PHONE_BOOK_MAIN_MENU
}PHONE_BOOK_MENU_CHOICE;


typedef struct id ID;
struct id {
	char address[10];
	int numMessages;
	char* DateReceived;
};


typedef struct Treenode *tlink;
struct Treenode{
	ID item;
	tlink pLeft;
	tlink pRight;
};


/*** Function Prototypes ***/
int phoneBookMenu(void);	//manages menu of phone book
void phoneBookSearch(void);	// begins implementation of phone book search
tlink newTreeNode(ID item, tlink left, tlink right);     // creates a new tree node using malloc()
tlink BSTInsert(tlink h, ID item);                  // Insert a key in the BST (uses szKey as before)
void BSTInit(void);                                 // creates an empty Binary Search Tree
ID BSTSearch(tlink h, char* searchKey);          // Search for a key in the BST (using szKey in struct Item)
ID Search(char* searchKey);
void Insert(ID item);                             // EDIT: Insert(Item item)
void BSTPrint(tlink h);								// print the nodes in order
int countNodes(tlink h);								// count the number of nodes in the BST
tlink getHead();										// get the head of the tree
int getHeight(tlink h);								// get the height of the tree
//link defineSearchKey(link h);						// defines the search key



#endif