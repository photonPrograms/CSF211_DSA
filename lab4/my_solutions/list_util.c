#include "list_util.h"

void *myalloc(size_t size) {
	void *p = malloc(size);
	space += size;
	return p;
}

void myfree(void *p, int size) {
	free(p);
	space -= size;
}

struct linkedlist *createList(int N) {
	// creation of an empty linkedlist
	struct linkedlist *Ls = (struct linkedlist*) myalloc(sizeof(struct linkedlist));
	Ls->count = 0;
	Ls->head = NULL;

	srand(time(NULL));

	struct node *prev = Ls->head;
	for (int i = 0; i < N; i++) {
		// new node creation
		struct node *curr = (struct node*) myalloc(sizeof(struct node));
		if(curr == NULL) {
			printf("Error: node creation failed.");
			break;
		}
		curr->element = rand();
		curr->next = NULL;

		// dealing with the first node
		if (Ls->count == 0)
			Ls->head = curr;

		// attaching new node to the end of the list
		else
			prev->next = curr;
		
		prev = curr;
		Ls->count++;
	}

	return Ls;
}

struct linkedlist* createCycle(struct linkedlist* Ls) {
	// if the coin flip results in 0
	// let the list remain as is
	// or if the list is empty
	if (rand() % 2 == 0 || Ls == NULL || Ls->count == 0)
		return Ls;

	// turning the list cyclic
	int r = rand() % (Ls->count); // position to be attached to end

	struct node *attach, *curr;

	curr = Ls->head;
	int i = 0;
	while (curr->next != NULL) {
		if (i == r)
			attach = curr;
		curr = curr->next;
	}
	curr->next = attach;

	return Ls;
}
