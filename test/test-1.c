#include <assert.h>
#include <stdio.h>
#include "../src/lock.h"

#define RUNS 10000

int main()
{
	lock(1);

	int i;
	int **arr = lock(RUNS * sizeof(int *));

	if (arr == NULL) {
		printf("Memory failed to allocate!\n");
		return 1;
	}
	assert(arr != NULL && "Memory failed to allocate");

	for (i = 0; i < RUNS; i++) {
		arr[i] = lock(sizeof(int));
		assert(arr[i] != NULL && "Memory failed to allocate");

		*(arr[i]) = i + 1;
	}

	for (i = 0; i < RUNS; i++) {
		assert((*(arr[i]) == i + 1) &&
		       "Memory failed to contain correct data after many allocations!\n");
	}

	for (i = 0; i < RUNS; i++) {
		za_hando(arr[i]);
	}

	za_hando(arr);
	printf("Passed test-1");
	return 0;
}
