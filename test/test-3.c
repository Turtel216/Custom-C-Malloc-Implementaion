#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../src/lock.h"

#define START_MALLOC_SIZE 1024 * 1024 * 128
#define STOP_MALLOC_SIZE 1024

void dummy(void)
{
	return;
}

void *reduce(void *ptr, int size)
{
	if (size > STOP_MALLOC_SIZE) {
		void *ptr1 = relock(ptr, size / 2);
		void *ptr2 = lock(size / 2);

		assert((ptr1 != NULL || ptr2 != NULL));

		ptr1 = reduce(ptr1, size / 2);
		ptr2 = reduce(ptr2, size / 2);

		assert((*((int *)ptr1) == size / 2 ||
			*((int *)ptr2) == size / 2) &&
		       "Memory failed to contain correct data after many allocations!\n");

		void *old_ptr1 = ptr1;
		ptr1 = relock(ptr1, size);
		za_hando(ptr2);

		if (*((int *)ptr1) != size / 2) {
			printf("Memory failed to contain correct data after realloc()!\n");
			printf("Expected %i found %i (old %i)\n", (size / 2),
			       *((int *)ptr1), *((int *)old_ptr1));
			dummy();
			exit(3);
		}

		*((int *)ptr1) = size;
		return ptr1;
	} else {
		*((int *)ptr) = size;
		return ptr;
	}
}

int main(void)
{
	lock(1);

	int size = START_MALLOC_SIZE;
	while (size > STOP_MALLOC_SIZE) {
		void *ptr = lock(size);
		ptr = reduce(ptr, size / 2);
		za_hando(ptr);

		size /= 2;
	}

	printf("Passed test-3\n");
	return 0;
}
