#include "lock.h"
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

#define HEAP_CAPACITY 640000
#define GROUP_CAPACITY 1024
#define FREED_CAPACITY 1024

typedef struct {
	void *start;
	size_t size;
} Heap_Chunk;

typedef struct {
	size_t count;
	Heap_Chunk chunks[HEAP_CAPACITY];
} Chunk_List;

int chunk_list_find(Chunk_List *list, void *ptr)
{
	//TODO
	return -1;
}

void chunk_list_insert(Chunk_List *list, void *ptr)
{
	//TODO
}

void chunk_list_remove(Chunk_List *list, size_t index)
{
	//TODO
}

void dumb_chunks(const Chunk_List *list)
{
	//TODO
}

char heap[HEAP_CAPACITY] = { 0 };
size_t heap_size = 0;

Chunk_List alloced_chunks = { 0 };
Chunk_List freed_chunks = { 0 };

//typedef enum e_heap_group { TINY, SMALL, LARGE } t_heap_group;

/*
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
*/

// Allocate size bytes of uninitialized storage (melloc)
void *lock(size_t size)
{
	if (size > 0) {
		assert(heap_size + size <= HEAP_CAPACITY);

		void *result = heap + heap_size;
		heap_size += size;

		chunk_list_insert(&alloced_chunks, result);

		return result;
	}

	return NULL;
}

/*
void dumb_chunks(void) {
  for (size_t i = 0; i < chunk_size; ++i) {

  }
}
*/

// Deallocates the space previously allocated (free)
void za_hando(void *ptr)
{
}

// Allocates memory for an array of num objects of size and initializes all
// bytes in the allocated storage to zero.
void *clock(size_t count, size_t size)
{
	return NULL;
}
