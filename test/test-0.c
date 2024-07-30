#include <assert.h>
#include <stdio.h>
#include "../src/lock.h"

int main()
{
	int *ptr = lock(sizeof(int));
	assert(ptr != NULL && "Failed to malloc a single int");

	*ptr = 1;
	*ptr = 100;

	za_hando(ptr);

	int *ptr2 = lock(sizeof(int));
	assert(ptr2 != NULL && "Failed to malloc a single int after free");

	*ptr2 = 2;
	*ptr2 = 200;

	za_hando(ptr2);

	lock(1); // Screw up alignment.

	int *ptr3 = lock(sizeof(int));
	assert(ptr3 != NULL && "Failed to malloc a single int after lock(1)");

	*ptr3 = 3;
	*ptr3 = 300;

	za_hando(ptr3);
	printf("Passed test-0");

	return 0;
}
