#include "lock.h"
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

#define HEAP_CAPACITY 640000
#define CHUNK_CAPACITY 1024

typedef struct {
	void *start;
	size_t size;
} Heap_Chunk;

typedef struct {
	size_t count;
	Heap_Chunk chunks[CHUNK_CAPACITY];
} Chunk_List;

int chunk_list_find(Chunk_List *list, void *ptr)
{
	//TODO
	return -1;
}

// Insert new node to list
void chunk_list_insert(Chunk_List *list, void *ptr, size_t size)
{
	assert(list->count < CHUNK_CAPACITY);

	list->chunks[list->count].start = ptr;
	list->chunks[list->count].size = size;

	for (size_t i = list->count;
	     i > 0 && list->chunks[i].start < list->chunks[i - 1].start; --i) {
		// Swap the current with previous chunk
		const Heap_Chunk t_chunk = list->chunks[i];
		list->chunks[i] = list->chunks[i - 1];
		list->chunks[i - 1] = t_chunk;
	}

	list->count += 1;
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

		chunk_list_insert(&alloced_chunks, result, size);

		return result;
	}

	return NULL;
}

// Deallocates the space previously allocated (free)
void za_hando(void *ptr)
{
	//TODO
}

// Allocates memory for an array of num objects of size and initializes all
// bytes in the allocated storage to zero.
void *clock(size_t count, size_t size)
{
	//TODO
	return NULL;
}
