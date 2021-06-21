#include <stdio.h>
#include <stdlib.h>

/* denotes true/false values */
typedef enum { FALSE, TRUE } Boolean;

/* individual element or node in the queue */
struct element {
	int val;
	struct element* next;
};
typedef struct element* Element;

/* the queue */
struct queue {
	Element head;
	Element tail;
	int count;
};
typedef struct queue* Queue;

Queue newQ();
/* returns an empty Queue */

Boolean isEmptyQ(Queue q);
/* tests whether q is empty */

Queue delQ(Queue q);
/* deletes the element at the front of q 
 * and returns the modified Queue
 */

Element front(Queue q);
/* returns the element at the front of q */

Queue addQ(Queue q, Element e);
/* adds e to the rear of q
 * and returns the modified Queue
 */

int lengthQ(Queue q);
/* returns the length of q */
