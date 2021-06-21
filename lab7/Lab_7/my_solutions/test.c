# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

# include "sorting.h"

# define DATA_LEN 100

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
