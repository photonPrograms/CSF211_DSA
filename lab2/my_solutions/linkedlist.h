/* linkedlist.h */

#include <stdio.h>
#include <stdlib.h>

// structure definitions

// structure of a linked list node
// it contains an element
struct node {
	int element;
	struct node *next;
};

// structure of a linked list or head
// it stores the count of elements in the list
// and a pointer to the first element
struct linkedList {
	int count;
	struct node *first;
};

// function declarations

void insertFirst(struct linkedList *head, int ele);
// inserts a given element at the beginning of the list

struct node* deleteFirst(struct linkedList *head);
// deletes the first element and returns pointer to it

void printList(struct linkedList *head);
// prints all elements in the list

int search(struct linkedList *head, int ele);
// searches for a given element in the list
// returns 1 if found, 0 otherwise

struct node* delete(struct linkedList *head, int ele);
// deletes the first node in the list that contains ele
// and returns pointer to it
// gives error message if element not found
