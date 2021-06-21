/* linkedlist.c */

#include "linkedlist.h"

/* insert a new first item */
void insertFirst(struct linkedList *head, int ele) {
	// create a node
	struct node *link = (struct node*) malloc(sizeof(struct node));
	link->element = ele;

	// point it to the old first node
	link->next = head->first;

	// point first to the new first node
	head->first = link;
	head->count++;
}

/* delete the first item */
struct node* deleteFirst(struct linkedList *head) {
	// get link to the old first node
	struct node *temp = head->first;

	// point first to the next node;
	head->first = temp->next;
	head->count--;

	return temp;
}

/* display the list */
void printList(struct linkedList *head) {
	struct node *ptr = head->first;
	printf("\n[ ");

	while (ptr != NULL) {
		printf("%d, ", ptr->element);
		ptr = ptr->next;
	}

	printf(" ]");
}

/* search for a given element */
int search(struct linkedList *head, int ele) {
	struct node *ptr = head->first;
	while (ptr != NULL) {
		if (ptr->element == ele)
			return 1;
		ptr = ptr->next;
	}
	return 0;
}

/* delete the given element */
struct node* delete(struct linkedList *head, int ele) {
	if (search(head, ele) == 0) {
		printf("Error: not found!");
		return NULL;
	}
	
	struct node* ptr = head->first;
	if (ptr->element == ele)
		return deleteFirst(head);

	while (ptr->next != NULL) {
		if ((ptr->next)->element == ele) {
			struct node *temp = ptr->next;
			ptr->next = temp->next;
			head->count--;
			return temp;
		}
		ptr = ptr->next;
	}
}
