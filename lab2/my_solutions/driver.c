/* driver.c */

#include <stdio.h>
#include "linkedlist.h"

int main(int argc, char *argv[]) {
	// create a file pointer and open the file read as cmd line arg
	FILE *fileptr = fopen(argv[1], "r");

	// declare a pointer to a linked list
	struct linkedList *head = (struct linkedList*) malloc(sizeof(struct linkedList));

	// read the file and insert elements into the list
	while (!feof(fileptr)) {
		int temp;
		fscanf(fileptr, "%d ", &temp);
		insertFirst(head, temp);
	}
	fclose(fileptr);

	printList(head);
	struct node* deleted = deleteFirst(head);
	free(deleted);
	printList(head);

	// printing updated list to a new file
	fileptr = fopen("listprinted.txt", "w");
	struct node* ptr = head->first;
	while (ptr != NULL) {
		fprintf(fileptr, "%d\n", ptr->element);
		ptr = ptr->next;
	}
	fclose(fileptr);
}
