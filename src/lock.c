#include "lock.h"
#include <stdio.h>
#include <stdbool.h>

typedef enum e_heap_group { TINY, SMALL, LARGE } t_heap_group;

typedef struct s_heap {
	struct s_heap *prev;
	struct s_heap *next;
	t_heap_group group;
	size_t size;
	size_t free_size;
	size_t count;
} t_heap;

typedef struct s_block {
	struct s_block *prev;
	struct s_block *next;
	size_t size;
	bool freed;
} t_block;

// Allocate size bytes of uninitialized storage (melloc)
void *lock(size_t size)
{
	if (size <= 0)
		return NULL;

	return NULL;
}

// Allocates memory for an array of num objects of size and initializes all
// bytes in the allocated storage to zero.
void *clock(size_t count, size_t size)
{
	if (size <= 0)
		return NULL;

	return NULL;
}
