#include <stdio.h>
#include "../src/lock.h"

int main()
{
	int *ptr = lock(sizeof(int));
	if (ptr == NULL) {
		printf("Failed to malloc a single int\n");
		return 1;
	}

	*ptr = 1;
	*ptr = 100;

	za_hando(ptr);

	printf("malloc'd an int, assigned to it, and free'd it\n");

	int *ptr2 = lock(sizeof(int));
	if (ptr2 == NULL) {
		printf("Failed to malloc a single int\n");
		return 1;
	}

	*ptr2 = 2;
	*ptr2 = 200;

	za_hando(ptr2);
	printf("malloc'd an int, assigned to it, and free'd it #2\n");

	lock(1); // Screw up alignment.

	int *ptr3 = lock(sizeof(int));
	if (ptr3 == NULL) {
		printf("Failed to malloc a single int\n");
		return 1;
	}

	*ptr3 = 3;
	*ptr3 = 300;

	za_hando(ptr3);
	printf("malloc'd an int, assigned to it, and free'd it #3\n");

	return 0;
}
