#ifndef HASHH
#define	HASHH

#include "list.h"

/* 
Alex Hockley
0758114

This is an ADT for a Hash Table which is capable of storing strings only */

typedef Node* ElementPtr;

struct hashTable
{
    ElementPtr* listPtr; /*Pointer to a list*/
    int size; /*Table size*/
    
};
typedef struct hashTable HTable;


/*
	Purpose: Initializes a hashtable and all of its elements (as pointers)
	Parameters: The size of the hashtable
	Preconditions: Size > 0
	Returns: An initialized hashtable
	PostConditions: A hash table has been created, and all elements have a dummynode
*/
HTable* createHash (int sizeArg);


/*
	Purpose: Destroys the hash table and all elements of it
	Parameters: A pointer to a hash table
	PreConditions: Hash table must exist
	Returns: Nothing
	PostConditions: The hash table has been destroyed, and all lists within it also. The hashtable where destroy is called must be set to NULL
	outside of the function so no errors occur later
*/
void destroyHash(HTable*);


/*
	Purpose: Inserts an element at the hash index
	Parameters: A pointer to a hashtable, the value you wish to insert
	PreConditions: Hash table must exist
	Returns: Nothing
	PostConditions: The same hash table, with the new value added at the appropriate position
*/
void insertHash (HTable*, char* value);



/*
	Purpose: Removes the list at the position of the hashtable
	Parameters: Pointer to hashtable, position you wish to remove
	PreConditions: Hash table must exist, position must be within the hashtable
	Returns: Nothing
	PostConditions: The has table remains the same, but that position has been deleted
*/
void removeHash (HTable*, int position);



/*
	Purpose: Looks up the list at the specified position to be used
	Parameters: Pointer to hashtable, position you would like to fetch
	PreConditions: Hashtable must exist, position must be within the hashtable
	Returns: The listhead at the position
	PostConditions: A listhead is returned from the function to be used, this is the entire list at that position in the hashtable
*/
Node* lookupHash (HTable*, int position);



/*
	Purpose: Updates a value on the hashtable
	Parameters: Pointer to a hashtable, the old string to look up, a new string for that spot
	PreConditions: Hashtable must exist
	Returns: Nothing
	PostConditions: The hashtable has been updated with the new value, everything else remains the same but the new value. The new value will not
	be able to be found by the hashfunction though, due to it not being used to determine its placement
*/
void updateHash (HTable*, char* oldValue, char *newValue);



/*
	Purpose: Determines the key for a given string
	Parameters: The size of the hashtable, a string
	PreConditions: None
	Returns: The key as an integer
	PostConditions: A key has been determined for that given string
*/
int hFunction(int sizeArg, char* value);


void toLC(char str []);

#endif
