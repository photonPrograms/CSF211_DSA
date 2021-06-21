#include "que.h"

typedef int Priority;
typedef int TaskID;

typedef struct {
	TaskID tid;
	Priority p; // starts from 1, not 0
} Task;

typedef struct queue* MultiQ;
/* MultiQ will be a pointer to an array of queues */

MultiQ createMQ(int num);
/* creates a MultiQ array of num queues */

MultiQ addMQ(MultiQ mq, Task t);
/* adds task t to Queue corresponding to its priority */

Task nextMQ(MultiQ mq);
/* returns the front of non-empty Queue in mq with highest priority */

MultiQ delNextMQ(MultiQ mq);
/* deletes the front of non-empty Queue in mq with highest priority
 * returns modified MultiQ
 */

Boolean isEmptyMQ(MultiQ mq);
/* checks if all Queues in MultiQ are empty */

int sizeMQ(MultiQ mq);
/* returns total number of tasks in MultiQ */

int sizeMQbyPriority(MultiQ mq, Priority p);
/* returns number of tasks in MultiQ with priority p */

Queue getQueueFromMQ(MultiQ mq, Priority p);
/* returns the Queue with priority p */
