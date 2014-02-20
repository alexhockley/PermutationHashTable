#include "hash.h"

/*
	Alex Hockley
	0758114
	Created: November 2nd 2012
	
	This tests the functions of the hash table adt in orders that should break it, the large number of values gets tested in the a2.c file
*/

int main (void)
{

  HTable *hashTable; /* creates variables */
  int num = 0;
  Node *temp;
  
  
  /*Creates table size 40*/
  printf ("Create table\n");
  hashTable = createHash(40);
  printf ("...Done\n");
  
  /*inserts a word Hello*/
  printf ("Inserting 'Hello'\n");
  insertHash (hashTable, "Hello");
  printf ("...Done\n");

  /*looks at index 24, which was determined to contain Hello*/
  printf ("lookup node 24\n");
  temp = lookupHash(hashTable,24);
  printf ("...Done\n");
  
  /*Prints the list at index 24 */
  printf ("list at 24 is:\n");
  printList(temp);
  
  
  
  /*Finds the position of Hello using the hash function */
  num = hFunction (40,"Hello");
  printf ("...Done\n"); 
  
  /*Removes the list at index 24 */
  printf ("Remove position %d\n", num);
  removeHash(hashTable, num);
  printf ("...Done\n");
  
  /* Looks at index 24, which was just removed */
  printf ("lookup node 24\n");
  temp = lookupHash(hashTable,24);
  printf ("...Done\n");
  
  /* Prints the list at index 24, which is still empty */
  printf ("list at 24 is:\n");
  printList(temp);
  
  /* Destroys the hash table (including the empty list at 24)*/
  printf ("Destroying table\n");
  destroyHash(hashTable);
  hashTable = NULL; /*Sets hash table to null for later use */
  printf ("...Done\n");
  
  /*Removes a position, which doesnt exist because hash table is gone */
  printf ("Remove position %d\n", num);
  removeHash(hashTable, num);
  printf ("...Done\n");
  
  /*Inserts into non-existent hash table */
  printf ("Inserting 'Hello'\n");
  insertHash (hashTable, "Hello");
  printf ("...Done\n");

		/* Recreates the hash table */
  printf ("Create table\n");
  hashTable = createHash(40);
  printf ("...Done\n");
  
  
  /* Inserts to new table */
  printf ("Inserting 'Hello'\n");
  insertHash (hashTable, "Hello");
  printf ("...Done\n");
  
  
  printf ("Updating 'Hello' to 'Yellow'\n");
  updateHash(hashTable, "Hello", "yellow");
  printf ("...Done\n");
  
  temp = hashTable->listPtr[24];
  /* Prints the list at index 24, which now contains yellow */
  printf ("list at 24 is:\n");
  printList(temp);
  
  /*Destroys table */
  printf ("Destroying table\n");
  destroyHash(hashTable);
  hashTable = NULL; /*Sets hash table to null for later use */
  printf ("...Done\n");
  
  /*Destroys non-existent table */
  printf ("Destroying table\n");
  destroyHash(hashTable);
  hashTable = NULL; /*Sets hash table to null for later use */
  printf ("...Done\n");
  
  
  return 1;
}
