/* stack.c */

#include "stack.h"

/* stack push operation */
void push(struct linkedList *head, int ele) {
	insertFirst(head, ele);
}

/* stack pop operation */
struct node* pop(struct linkedList *head) {
	return deleteFirst(head);
}
