#include <stdio.h>

// Allocate size bytes of uninitialized storage (melloc)
void lock(size_t size);
// Deallocates the space previously allocated (free)
void ze_hando(void *ptr);
// Allocates memory for an array of num objects of size and initializes all
// bytes in the allocated storage to zero.
void clock(size_t count, size_t size);
// Reallocates the given area of memory.
void relock(void *ptr, size_t size);
