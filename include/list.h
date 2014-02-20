#ifndef LISTH
#define LISTH

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


/* 
Alex Hockley
0758114

this list structure is capable of storing strings only */

struct listNode 
{
	/* Data */
	char* nodeString;
	
	/* A pointer to the next node for making a linked list */
	struct listNode *next;
	
};
typedef struct listNode Node;



/* Purpose: Creates an initial node head, called dummy node 
   Parameters: None
   Returns: The dummy node, which will act as a list-head.
   PostConditions: A created list with a dummy node as the list head
*/
Node* createList ();



/* Purpose: Destroys the entire list, including the dummy node
   Parameters: A pointer to the list head
   Preconditions: List head has to be initialized to NULL to avoid a seg fault when destroying an empty list
   Returns: Nothing
   PostConditions: No list, because it has been obliterated
*/
void destroyList(Node *listHead);



/* Purpose: Destroys a node and sets the memory to zero/null values
   Parameters: Node to be destroyed
   Preconditions: If the node is in the middle of the list, the list will be broken
   Returns: Nothing
   PostConditions: A node has been destroyed
*/
void destroyNode(Node *node);



/* Purpose: Adds the newly initialized node to the front of the list
   Parameters: A pointer to the head of the list, a pointer to the node you are adding
   Preconditions: A pre-allocated list head
   Returns: The list-head via pointer
   PostConditions: A list that is one longer, because it has a new element
*/
void addFront (Node *listHead , Node *element);



/* Purpose: Prints the list to the console
   Parameters: A pointer to a list-head
   Preconditions: None
   Returns: Nothing
   PostConditions: A list is printed to the screen, nothing else changes
*/
void printList(Node *listHead);



/* Purpose: Initializes the new node
   Parameters: A string
   Preconditions: None
   Returns: A pointer to a node (which is the new node in memory)
   PostConditions: An initialized node that can then be added to a string/printed/etc
*/
Node* initNode(char* string);


/* Does nothing?
*/
char* getValue (Node *listHead, int nodeNum);


/* Purpose: Removes the head value of the list, but keeps the dummy node
   Parameters: A pointer to the list head
   Preconditions: None
   Returns: The new, edited list via pointer
   PostConditions: The list has been modified to be the same, minus the first node (not dummynode)
*/
Node* removeFront (Node *listHead);


/* Purpose: Looks through a list to see if the term is within any of the nodes
   Parameters: A point to the head of the list, a pointer to a string
   Preconditions: List cannot be null, term cannot be null
   Returns: Nothing
   Postconditions: The function will print all matches
*/
void checkList (Node *listHead, char* term);

#endif
