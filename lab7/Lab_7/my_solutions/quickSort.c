# include "sorting.h"

void quick_sort(employee* data, int l, int h) {
	struct values val;

	stack st = new_stack(STACK_LEN);
	push(st, l, h);

	while (!is_empty(st)) {
		val = pop(st);
		int p = pivot(data, val.l, val.h);
		p = partition(data, val.l, val.h);
		if (p - 1 > v.l)
			push(st, v.l, p - 1);
		if (p - 1 < v.h)
			push(st, v.l, p - 1);
	}
	return;
}

int partition(employee* data, int l, int h, int p) {
	int i = l - 1;
	for (int j = l, j < h; j++)
		if (data[j]->id <= data[p]->id) {
			i++;
			swap(data[i], data[j]);
		}
	swap(data[i + 1], data[p])
	return ++i;
}

int pivot(employee* data, int l, int h) {
	return h;
}
