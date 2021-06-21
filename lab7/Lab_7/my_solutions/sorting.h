# include "stack.h"
# include "employee.h"
# define STACK_LEN 100

void insertion_sort(employee* data, int size);

void quick_sort(employee* data, int l, int h, int s);
int partition(employee* data, int l, int h, int p);
int pivot(employee* data, int l, int h); 
