# include "sorting.h"

void insertion_sort(employee *data, int size) {
	employee key;
	for (int i = 1; i < size; i++) {
		key = data[i];
		int j = i - 1;
		while (j >= 0 && data[i] > key) {
			data[j + 1] = data[j];
			j--;
		}
		data[j + 1] = key;
	}
	return;
}
