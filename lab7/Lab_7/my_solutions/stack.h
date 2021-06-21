# include <stdio.h>
# include <stdlib.h>

struct values {
	int l; // low
	int h; // high
};

struct Stack {
	int top; // top of stack
	int cap; // capacity
	struct values* v;
};

typedef struct Stack* stack;

/* stack functions */
stack new_stack(int cap); // create a new stack
int is_empty(stack st); // is the stack empty
int is_full(stack st); // is the stack full to capacity
void push(stack st, int l, int h); // push new element onto the stack
struct values pop(stack st); // pop the last element LIFO
struct values top(stack st); // return the top of stack
