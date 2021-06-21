# include <stdio.h>
# include <string.h>

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
