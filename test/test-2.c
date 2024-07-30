#include <stdio.h>
#include "../src/lock.h"

#define TOTAL_ALLOCS 200000
#define ALLOC_SIZE 1024 * 1024

int main()
{
	lock(1);

	int i;
	void *ptr = NULL;

	for (i = 0; i < TOTAL_ALLOCS; i++) {
		ptr = lock(ALLOC_SIZE);
		if (ptr == NULL) {
			printf("Memory failed to allocate!\n");
			return 1;
		}

		za_hando(ptr);
	}

	printf("Passed test-2\n");
	return 0;
}
