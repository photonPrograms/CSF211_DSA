# include "employee.h"

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
