#include <sys/time.h>
#include "multiq.h"

#define MAXPRI 10 // maximum priority in the given file

MultiQ mq;

MultiQ loadData(FILE *fptr);
MultiQ testDel(int num);

int main(int argc, char* argv[]) {
	struct timeval t1, t2;
	double elapsedTime;

	if (argc != 2)
		return 0;

	FILE *fptr = fopen(argv[1], "r");

	gettimeofday(&t1, NULL);
	mq = loadData(fptr);
	gettimeofday(&t2, NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000;
	elapsedTime = (t2.tv_usec - t1.tv_usec) / 1000;
	printf("loadData took %f ms.\n", elapsedTime);


	gettimeofday(&t1, NULL);
	mq = testDel(MAXPRI);
	gettimeofday(&t2, NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000;
	elapsedTime = (t2.tv_usec - t1.tv_usec) / 1000;
	printf("testDel took %f ms.\n", elapsedTime);
	
	return 0;
}

MultiQ loadData(FILE *fptr) {
	if (!fptr) {
		printf("Error: file can not be opened.\n");
		exit(0);
	}

	MultiQ m = createMQ(MAXPRI);

	int id, pri;
	Task t;
	while (fscanf(fptr, "%d,%d", &id, &pri) == 2) {
		t.tid = id;
		t.p = pri;
		m = addMQ(m, t);
	}
	return m;
}

MultiQ testDel(int num) {
	for (int i = 0; i < num; i++)
		mq = delNextMQ(mq);
	return mq;
}
