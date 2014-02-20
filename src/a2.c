#include "hash.h"

/* 
Alex Hockley
0758114
Assignment 2 Dictionary Lookup/Store

This program uses the Hash Table data structure to store a dictionary file. The user can then enter a sequence of letters. The program
will then generate anagrams of that sequence of letters and search the dictionary table to see if that word is within it.
*/


/* function headers */
void swap (char *x, char *y);
int genAnag(HTable *hashTable, int tSize,char *str, int i, int n, int perm);
void toLC(char str []);




int main (void)
{
  FILE *inputFile = NULL; /*Creates input file variable*/
  
  char buffer [100]; /*Buffer for inputting from file*/
  
  HTable *hashTable; /*hash table*/
  
  int i = 0; /*Counter */
  int flag = 0; /*Flag for input 1 true, 0 false*/
  
  int tSize = 234979/2; /*Sets size of hash table size of dict  /2 */
  int permutations = 0; /*counter for number of permuation */
  
  char a[100]; /*input word*/
  
  
  inputFile = fopen ("dictionaryfile.txt", "r"); /*Opens dictionary file for reading */


  
  
  if (inputFile == NULL) /*Checks if file was opened properly */
  {
      printf ( "Error. Input file does not exist!\n");
      exit(1); /*Closes program */
  }
  else
  {
    
    
    hashTable = createHash(tSize);/*initializes the hash table */
    while (fgets (buffer, 100, inputFile) != NULL) /* From Prof. McCuaig;  Buffer reads in from the file, one line at a time */
    {
        for(i = 0; i<100; i++) /*removes newline from buffer */
        {
	           if (buffer[i] =='\n') /* sets to null character */
			   		buffer[i] = '\0';
        }
        
        toLC(buffer); /* inserts into hash table as lowercase*/
        insertHash (hashTable, buffer); /*Inserts each dictionary word into the hash table */
      
    }
    
    /*continues to ask for a word until valid */
    while (flag == 0)
    {
    	   printf ("\nEnter a word to permutate: "); /*promps for input */
    	   scanf ("%s", a);
    	   
    	   if (strlen(a) <11 && strlen(a) > 2) /*if inside range */
    	       flag = 1;/*valid */
    	   else
    	       printf ("Invalid world length, between 2 and 10 characters please\n"); /*Displays error */
    	       
    }
    
    toLC(a); /* Makes input all lowercase for comparison */
    
    printf ("\n\n **Matches** \n\n");
    
    permutations = genAnag(hashTable, tSize, a, 0, strlen(a)-1, permutations); /*generates anagrams and searches the hash table for each word, also calculates total permutations */
    
    printf ("**Done searching**\n\n");
    
    
    printf ("\n\nTotal permutations %d\n", permutations); /*Prints total permutations */
    
  }

  destroyHash(hashTable);
  hashTable = NULL;
  
  return 1;
}







/* Purpose: Swaps two letters in a string
   Parameters: Two character pointers for swapping
   Preconditions: None
   Returns: Nothing
   PostConditions: A new string with swapped characters
   
swap and genAnag functions from http://www.geeksforgeeks.org/archives/767*/
void swap (char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
  
/* Purpose: Function to print permutations of string. Searches the hash table for each individual string and prints if theres a match
   Parameters: A hash table pointer, size of the table, string to generate anagrams for,index for start of anagram,index for end of anagram, number of current permutations init at 0
   Preconditions: Non-null hash table, tablesize > 0, string longer than 2, first pass permutations should be 0 from initial function call
   Returns: The number of permuatations
   Postconditions: No variables are changed, but the matched strings are printed to the screen, and the number of permutations are counted
   */

int genAnag(HTable *tempHash, int tSize,char *string, int i, int n, int perm) 
{
   int j = 0;
   
   if (i == n)
   {
     Node *lookup = lookupHash(tempHash, hFunction(tSize,string)); /*Assigns table position*/
     checkList(lookup,string); /*checks the nodes at that table position */
     perm++; /*increments permutation counter */
   }
   else
   {
       for (j = i; j <= n; j++)
       {
          swap((string+i), (string+j));
          perm = genAnag(tempHash, tSize ,string, i+1, n, perm);
          swap((string+i), (string+j)); /*backtrack*/
       }
   }
   return perm;
} 


/*
	Purpose: To convert a string array to lowercase
	Parameters: A string array
	Preconditions: String must be less than length 10
	Returns: Nothing
	Postconditions: A string of all lowercase letters
*/
void toLC (char str [10])
{
	int i = 0;
	char temp;
	for(i = 0; i < strlen(str); i++)
	{
		temp = str[i];
		temp = tolower(temp);
		str[i] = temp;
    }

}   
