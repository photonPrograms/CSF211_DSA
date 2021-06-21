/* stackdriver.c : a driver for stack operations */

#include "stack.h"

int main(int argc, char *argv[]) {
	FILE *fptr = fopen(argv[1], "r");
	
	struct linkedList *stack = (struct linkedList*) malloc(sizeof(struct linkedList*));

	while (!feof(fptr)) {
		int temp;
		fscanf(fptr, "%d ", &temp);
		push(stack, temp);
	}
	fclose(fptr);

	int count = stack->count;
	for (int i = 0; i < count; i++) {
		struct node *curr = pop(stack);
		printf("%d\n", curr->element);
		free(curr);
	}
}	
