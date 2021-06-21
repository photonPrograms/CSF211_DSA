/* for functions and definitions
 * common to linked list exercises
 * in lab 4
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

extern int space; 
/* for keeping record of space allocated 
 * as required by myalloc() and myfree()
 */

struct node {
	int element;
	struct node *next;
};
// individual list element

struct linkedlist {
	int count;	// number of elements in linkedlist
	struct node *head; // points to the beginning/head
};
// linked list adt

void *myalloc(size_t size);
/* to allocate space using malloc() */

void myfree(void *p, int size);
/* to free() up space pointed to by p */

struct linkedlist *createList(int N);
/* creates a linearly linked list of N elements */

struct linkedlist* createCycle(struct linkedlist* Ls);
/* creates a cycle in the linkedlist based on probability */
