#include "multiq.h"

int nque; // to record the possible number of queues in MultiQ

MultiQ createMQ(int num) {
	MultiQ mq = (MultiQ) malloc(sizeof(struct queue) * num);
	nque = num;
	
	// creating nque empty queues
	for (int i = 0; i < nque; i++) {
		struct queue qu = mq[i];
		qu.count = 0;
		qu.head = NULL;
		qu.tail = NULL;
	}
	
	return mq;
}

MultiQ addMQ(MultiQ mq, Task t) {
	// creating an element out of the task
	Element e = (Element) malloc(sizeof(struct element));
	e->val = t.tid;
	e->next = NULL;

	// adding element to the queue
	addQ(&mq[t.p - 1], e);

	return mq;
}

Task nextMQ(MultiQ mq) {
	Task t = {0, 0};

	// assuming higher the priority number, higher the priority
	if (!isEmptyMQ(mq))
		for (int i = nque - 1; i >= 0; i--)
			if (!isEmptyQ(&mq[i])) {
				Element e = front(&mq[i]);
				t.tid = e->val;
				t.p = i + 1;
				return t;
			}

	return t;
}

MultiQ delNextMQ(MultiQ mq) {
	if (isEmptyMQ(mq)) {
		printf("ERROR: empty multi-queue.\n");
		return mq;
	}
	for (int i = nque - 1; i >= 0; i--)
		if (!isEmptyQ(&mq[i])) {
			Queue q = delQ(&mq[i]);
			mq[i] = *q;
			return mq;
		}
}

Boolean isEmptyMQ(MultiQ mq) {
	for (int i = 0; i < nque; i++)
		if (!isEmptyQ(&mq[i]))
			return FALSE;
	return TRUE;
}

int sizeMQ(MultiQ mq) {
	int size = 0;
	for (int i = 0; i < nque; i++)
			size += lengthQ(&mq[i]);
	return size;
}

int sizeMQbyPriority(MultiQ mq, Priority p) {
	return lengthQ(&mq[p - 1]);
}

Queue getQueueFromMQ(MultiQ mq, Priority p) {
	return &mq[p - 1];
}
