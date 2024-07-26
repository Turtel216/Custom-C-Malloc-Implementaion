#include "lock.h"
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>

// Linked list node
typedef struct Chunk {
	size_t size;
	struct Chunk *next; // pointer to next node
	bool freed; // keeps track of freed chunks
	int temp_debug; // TODO remove after debugging
} Chunk;

#define CHUNK_SIZE sizeof(Chunk)

void *head = NULL; // Link list head

// Find available memory in the heap
Chunk *find_free_chunk(Chunk **last, size_t size)
{
	Chunk *current = head;
	while (current && !(current->freed && current->size >= size)) {
		*last = current;
		current = current->next;
	}

	return current;
}

Chunk *request_space(Chunk *last, size_t size)
{
	Chunk *chunk;
	chunk = sbrk(0);
	void *request = sbrk(size + CHUNK_SIZE);

	assert((void *)chunk == request);
	if (request == (void *)-1) {
		return NULL; // sbrk failed.
	}

	if (last) { // NULL on first request.
		last->next = chunk;
	}
	chunk->size = size;
	chunk->next = NULL;
	chunk->freed = false;
	chunk->temp_debug = 0x12345678;
	return chunk;
}

Chunk *get_block_ptr(void *ptr)
{
	return (Chunk *)ptr - 1;
}

// Allocate size bytes of uninitialized storage (melloc)
void *lock(size_t size)
{
	//TODO
	return NULL;
}

// Deallocates the space previously allocated (free)
void za_hando(void *ptr)
{
	if (!ptr) {
		return;
	}

	// TODO merge chunks once splitting chunks is implemented.
	Chunk *chunk_ptr = get_block_ptr(ptr);
	assert(chunk_ptr->freed == false);
	assert(chunk_ptr->temp_debug == 0x77777777 ||
	       chunk_ptr->temp_debug == 0x12345678);

	chunk_ptr->freed = true;
	chunk_ptr->temp_debug = 0x55555555;
}

// Reallocates the given area of memory.
void *relock(void *ptr, size_t size)
{
	if (!ptr) {
		// NULL ptr. relock should act like lock.
		return lock(size);
	}

	Chunk *chunk = get_block_ptr(ptr);
	if (chunk->size >= size) {
		// TODO free some space once we implement split.
		return ptr;
	}

	// Lalloc new space and free old space.
	// Then copy old data to new space.
	void *new_ptr;
	new_ptr = lock(size);
	if (!new_ptr) {
		return NULL; // TODO: set errno on failure.
	}
	memcpy(new_ptr, ptr, chunk->size);
	za_hando(ptr);
	return new_ptr;
}

// Allocates memory for an array of num objects of size and initializes all
// bytes in the allocated storage to zero.
void *clock(size_t count, size_t size)
{
	size_t sum = count * size; // TODO check for overflow.
	void *ptr = lock(sum);
	memset(ptr, 0, sum);
	return ptr;
}
