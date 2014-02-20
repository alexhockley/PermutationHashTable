#include "list.h"

/* Alex Hockley 0758114 
   Created: September 21 2012
   Modified: October 8 2012
   
   A list ADT only capable of storing strings
   */



Node* createList()
{
    Node *dummyNode = malloc (sizeof(Node));
    dummyNode->next = NULL;
    dummyNode->nodeString = NULL;
    return dummyNode;
}


void destroyList(Node *listHead)
{
   Node *toDestroy;
   Node *temp;
   
   if (listHead != NULL)
   {
       temp = listHead;
   
       while (temp != NULL)
       {
           toDestroy = temp;
   	   	   temp = temp->next;
      	    
           destroyNode (toDestroy);
       }
       
   }
       
   
    
}



void destroyNode(Node *node)
{
    if (node != NULL)
    {
        node->nodeString = NULL;
        free (node->nodeString);
        node->next = NULL;
        free(node);
    }
   
}


Node* initNode (char *string)
{
    
    Node *newNode = malloc (sizeof(Node));
    char *addStr = malloc(sizeof(char*)*(strlen(string)-1)); /* Allocates the memory for the string */
    
    strcpy (addStr,string); /* Copies the string to the memory */
    
    newNode->nodeString = addStr; /* Assigns the string to the node */
    newNode->next = NULL;
    
    return newNode;
}


void addFront (Node *listHead, Node *newNode)
{
    
    newNode->next = listHead->next;
    listHead->next = newNode;    
        
}


void printList (Node *listHead)
{
   if (listHead!=NULL)
   {
    	
   	Node *currPos = listHead -> next; /* Creates a new node list so the old one is not lost during cycles. Ignores dummy node */

   	while (currPos != NULL)
  	{
      	    printf ("%s\n", currPos->nodeString);
      
      	    currPos = currPos->next;
      
   	}
   	
   }
}



Node* removeFront (Node *listHead)
{
   Node* temp;
   Node* toRemove;
   
   /* Removes first node with a value, keeps dummy, re-assigns dummy's next */
   if (listHead != NULL)
   {
       toRemove = listHead->next;
       if (toRemove != NULL)
       {
           temp = toRemove->next;
           listHead->next = temp;
   
           
       }
       
   }
   return toRemove;
   
   
}


void checkList (Node *listHead, char *term)
{
  
  if (listHead!=NULL)
   {
    	
   	Node *currPos = listHead -> next; /* Creates a new node list so the old one is not lost during cycles. Ignores dummy node */
	
   	while (currPos != NULL)
  	{

      	if(strcmp(term,currPos->nodeString) == 0) /* if strings are the same */
	    {
	      printf ("Match! %s is here\n", term); /*print match */
	    }
      
      	    currPos = currPos->next; /*next list element*/
      
   	}
   	
   }
  
}
   
   

    
