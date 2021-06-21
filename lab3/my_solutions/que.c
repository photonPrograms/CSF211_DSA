#include "que.h"

Queue newQ() {
	Queue q = (Queue) malloc(sizeof(struct queue));
	
	// initialization of the queue attributes
	q->head = NULL;
	q->tail = NULL;
	q->count = 0;

	return q;
}

Boolean isEmptyQ(Queue q) {
	if (q->count == 0)
		return TRUE;
	return FALSE;
}

Queue delQ(Queue q) {
	// making sure the queue is not empty
	if (isEmptyQ(q)) {
		printf("ERROR: delete operation attempted on empty queue.\n");
		return q;
	}

	Element curr = q->head;
	q->head = curr->next;
	free(curr);
	q->count--;

	return q;
}

Element front(Queue q) {
	return q->head;
	// NULL will be returned
	// in case the queue is empty
}

Queue addQ(Queue q, Element e) {
	if (isEmptyQ(q))
		q->head = e;
	else {
		Element temp = q->tail;
		temp->next = e;
	}
	q->tail = e;
	q->count++;

	return q;
}

int lengthQ(Queue q) {
	return q->count;
}
