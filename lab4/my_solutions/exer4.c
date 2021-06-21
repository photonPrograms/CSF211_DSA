#include "cycle.h"
#include <sys/time.h>

int space = 0;

int main() {
	struct timeval t1, t2;
	double elapsedTime;
	srand(time(NULL));

	for (int i = 0, s = 1; i < 7; i++, s *= 10) {
		gettimeofday(&t1, NULL);
		struct linkedlist *Ls = createList(s);
		Ls = createCycle(Ls);
		printf("%d\n", testCyclic(Ls));
		gettimeofday(&t2, NULL);
		elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000
			+ (t2.tv_usec - t1.tv_usec) / 1000;
		printf("%d,%f,%d\n", s, elapsedTime, space);
	}
	return 0;
}
