#include "hash.h"
/* 
Alex Hockley
0758114

This is an ADT for a Hash Table which is capable of storing strings only */




HTable* createHash (int sizeArg)
{
	int i = 0; /* Counter */

	HTable *tempHash = malloc (sizeof(HTable)); /*Creates table*/
	tempHash->size = sizeArg; /*Inits size */
	tempHash->listPtr = malloc(sizeof(ElementPtr)*sizeArg);
	
	for(i=0; i < tempHash->size; i++) /* Cycles through the hash table, creating dummy nodes for the lists */
	{
		tempHash->listPtr[i] = createList();
	}
	
	
	return tempHash; /*Returns the hash table*/
	
}


void destroyHash (HTable *hashArg)
{
	int i = 0;
	
	if (hashArg != NULL) /*Checks if hash table exists */
	{
		  for (i = 0; hashArg->listPtr[i] != NULL; i++) /*Loops through elements */
		  {
			     destroyList(hashArg->listPtr[i]); /*Frees the list at table positions */
			     hashArg->listPtr[i] = NULL; /* sets position to null for cleanup */
		  }
		  hashArg->listPtr = NULL;
		  hashArg->size = 0;
		
		  free(hashArg->listPtr); /*Frees list pointer in the hash table */
		  free(hashArg); /*frees the hash table */
	}
	else
	    printf ("There is no table to destroy\n");
	/* hash table must be set to NULL in function where destroyHash() is called */
}


void insertHash (HTable *hashArg, char* value)
{
    if (hashArg != NULL)
    {
	
		   int position = hFunction(hashArg->size, value); /*determines position of the string */
	
	       Node* newNode = initNode(value); /*Creates a new node to be added to the hash table */
	       if (hashArg->listPtr[position] != NULL)
	       {
		           addFront(hashArg->listPtr[position], newNode); /*Adds the new node to the hash table */
	       }
	       else
	       {
		          hashArg->listPtr[position] = createList();     /*Creates list head with a dummy node */
		          addFront (hashArg->listPtr[position], newNode); /*Adds the new node to the hash table */
	       }
    }
    else 
      printf ("There is no hash table, no insert was performed\n");
	
}


void removeHash (HTable *hashArg, int position)
{
    if (hashArg != NULL)
    {
	if (hashArg->listPtr[position] != NULL)
	{
		destroyList(hashArg->listPtr[position]);
		hashArg->listPtr[position] = NULL;
	}
	else
	{
		printf ("There is no list here\n");
	}
    }
    else
      printf ("There is no hash table\n");
	
}



/*Will return the list at the table position, can be printed via the list operations */
Node* lookupHash(HTable *hashArg, int position)
{
	return (hashArg->listPtr[position]);	
}	


void updateHash (HTable *hashArg, char *oldValue, char *newValue)
{
	Node *temp; /*Pointers for looping */
	Node *currPos;
	
	
	int position = hFunction (hashArg->size, oldValue); /*Determines position*/
	
	temp = hashArg->listPtr[position];
	
	if (temp != NULL) /*checks if list exists */
	{
		currPos = temp->next;
		
		while (currPos != NULL)
		{
			if(strcmp(oldValue,currPos->nodeString) == 0) /* oldvalue is in the list */
	    	{
		      	currPos->nodeString = newValue; /*update */
	  	  	}
      
      	    currPos = currPos->next; /*next list element*/
      	}
      
   	}

}




/* Hash function from http://stackoverflow.com/questions/8567238/hash-function-in-c-for-string-to-int */
int hFunction (int sizeArg, char* value)
{
	int key = 0;
	int i = 0;
	for ( i = 0; i < strlen(value); i++) /* Continues to go through the whole string */
	{
		key = 37*key + (int)value[i]; /* increases the key by a product of 37, then adds the ascii value of the string character */
	}
	
	return abs(key % sizeArg); /* limits key to size of table */
	
	
}	
	
	
	
