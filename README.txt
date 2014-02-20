


a2.c README:
Alex Hockley
0758114
Created: November 2 2012



******************************
KNOWN ISSUES/LIMITATIONS
******************************
- Hardcoded to have a table size of 234979/2 hashes
- Prints duplicates of dictionary words
- When a value is updated, the new value cannot be found via hash function since it was manually inserted in the wrong spot
- Remove in the HASH ADT may not work as you inteded, want entirely sure what it was supposed to do


******************************
TESTING A2.c
******************************
- Ran with the given test file, and it passed


******************************
TESTING HASH ADT
******************************
- The has adt was tested by:
	Performing each of the operations in many different orders that would break the list and cause segfaults/errors.
	Each hardcoded test passed without issues
	For more description of what happened, see test.c
	



******************************
Testing/Running Instructions:
******************************
- Extract the .zip file into a directory of your choice
- Go to the ~/PermutationHashTable directory in your command terminal and type "make".
- After the make, ./bin/a2 for the dictionary program, type ./bin/test for the hardcoded testing program
--- MAKEFILE WILL HAVE TO BE MODIFIED ---






*******************************
Academic Integrity Pledge
*******************************

I have exclusive control over this submission via my password.
By including this file with my submitted files, I certify that:

1) I have read and understood the University policy on academic integrity;
2) I have completed the Computing with Integrity Tutorial on Moodle; and
3) I have achieved at least 80% in the Computing with Integrity Self Test.

I assert that this work is my own.

I have appropriately acknowledged any and all material (data, images, ideas or
words) that I have used, whether directly quoted or paraphrased.  Furthermore,
I certify that this assignment was prepared by me specifically for this course.
