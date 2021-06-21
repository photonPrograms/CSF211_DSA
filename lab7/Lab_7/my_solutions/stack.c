# include "stack.h"

// create a new stack
stack new_stack(int cap) {
	stack st = (stack) malloc(sizeof(struct Stack));
	st->top = -1;
	st->cap = cap;
	st->v = (struct values*) malloc(sizeof(cap * sizeof(struct values)));
	return st;
}

// is the stack empty
int is_empty(stack st) {
	return st->top == -1 ? 1 : 0;
}

// is the stack full to its capacity
int is_full(stack st) {
	return st->top == st->cap ? 1 : 0;
}

// push new item onto stack
void push(stack st, int l, int h) {
	if (is_full(st))
		return;
	struct values v;
	v.l = l;
	v.h = h;
	st->v[st->top + 1] = v;
}


// pop the last entered item
struct values pop(stack st) {
	if (is_empty(st)) {
		struct values v; // dummy structure
		return v;
	}
	return st->v[st->top--];
}

// top of the stack without removal
struct values top(stack st) {
	if (is_empty(st)) {
		struct values v;
		return v;
	}
	return st->v[st->top];
}
