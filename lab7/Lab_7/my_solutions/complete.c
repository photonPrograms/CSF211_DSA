# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

# define STACK_LEN 100
# define DATA_LEN 100

/* structure to hold information
 * in an individual employee record
 */
struct Employee {
	int id;
	char name[11];
};

typedef struct Employee* employee;

void swap(employee e1, employee e2);
void print_records(employee *data, int size);

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

void insertion_sort(employee* data, int size);

void quick_sort(employee* data, int l, int h, int s);
int partition(employee* data, int l, int h, int p);
int pivot(employee* data, int l, int h);

double testRun(employee* data, int count) {
	clock_t start, end;
	double quick, insert;

	printf("count: %d\n", count);
	if (!count)
		return 0;

	// copying data for testing
	employee copy1[count], copy2[count];
	for (int i = 0; i < count; i++) {
		copy1[i] = (employee) malloc(sizeof(struct Employee));
		copy1[i] = data[i];
		copy2[i] = (employee) malloc(sizeof(struct Employee));
		copy2[i] = data[i];
	}

	// time measurement for quick sort
	start = clock();
	quick_sort(copy1, 0, count - 1, 0); // s = 0
	end = clock();
	quick = ((double) end - start) / CLOCKS_PER_SEC * 100;

	// time measurement for insertion sort
	start = clock();
	insertion_sort(copy1, count); // s = 0
	end = clock();
	insert = ((double) end - start) / CLOCKS_PER_SEC * 100;

	/*for (int i = 0; i < count; i++) {
		free(copy1[i]);
		free(copy2[i]);
	}*/

	double diff = insert - quick;
	printf("%lf - %lf = %lf\n", insert, quick, diff);
	return diff;
}

int estimateCutoff(employee* data, int count) {
	double tt1, tt2, tt;
	int min = 0, max = count;
	int mid = (min + max) / 2;

	do {
		mid = (min + max) / 2;
		tt1 = testRun(data, (min + mid) / 2);
		tt = testRun(data, mid);
		tt2 = testRun(data, (mid + max) / 2);
		printf("%d %d %d; %lf %lf %lf\n", min, max, max, tt1, tt, tt2);
		if (tt2 < tt) {
			min = mid;
			continue;
		}
		max = mid;
	}
	while (min < mid && max > mid);

	return mid;
}

int main(int argc, char* argv[]) {
	if (argc != 3) {
		printf("Incorrect usage");
		return -1;
	}

	FILE *fp = NULL;

	fp = fopen(argv[1], "r");
	if (fp == NULL) {
		printf("File error");
		return -1;
	}
	fclose(fp);
	employee data[DATA_LEN];

	int i = -1;
	while (!feof(fp)) {
		data[++i] = (employee) malloc(sizeof(struct Employee));
		fscanf(fp, "%s %d", data[i]->name, &data[i]->id);
	}

	int cutoff = estimateCutoff(data, i);
	printf("%d\n", cutoff);

	// sorting to output file
	insertion_sort(data, i);
	fp = fopen(argv[2], "w");
	if (fp == NULL) {
		printf("File error");
		return -1;
	}
	
	for (int j = 0; j < i; j++)
		fprintf(fp, "%d %s\n", data[j]->id, data[j]->name);

	fclose(fp);

	return 0;
}

// swap two records
void swap(employee e1, employee e2) {
	struct Employee temp;
	strcpy(temp.name, e1->name);
	temp.id = e1->id;
	strcpy(e1->name, e2->name);
	e1->id = e2->id;
	strcpy(e2->name, temp.name);
	e2->id = temp.id;
	return;
}

// print all the employee data
void print_records(employee* data, int size) {
	for (int i = 0; i < size; i++)
		printf("%d, %s\n", data[i]->id, data[i]->name);
}

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

void insertion_sort(employee *data, int size) {
	employee key;
	for (int i = 1; i < size; i++) {
		key = data[i];
		int j = i - 1;
		while (j >= 0 && data[i]->id > key->id) {
			data[j + 1] = data[j];
			j--;
		}
		data[j + 1] = key;
	}
	return;
}

void quick_sort(employee* data, int l, int h, int s) {
	struct values v;

	stack st = new_stack(STACK_LEN);
	push(st, l, h);

	while (!is_empty(st)) {
		v = pop(st);
		int p = pivot(data, v.l, v.h);
		if (v.h - v.l > s)
			p = partition(data, v.l, v.h, p);
		if (p - 1 > v.l)
			push(st, v.l, p - 1);
		if (p - 1 < v.h)
			push(st, v.l, p - 1);
	}
	return;
}

int partition(employee* data, int l, int h, int p) {
	int i = l - 1;
	for (int j = l; j < h; j++)
		if (data[j]->id <= data[p]->id) {
			i++;
			swap(data[i], data[j]);
		}
	swap(data[i + 1], data[p]);
	return ++i;
}

int pivot(employee* data, int l, int h) {
	return h;
}
