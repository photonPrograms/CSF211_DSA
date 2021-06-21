# include "sorting.h"

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
