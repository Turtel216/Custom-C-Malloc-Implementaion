# Custom-C-Malloc-Implementation
An implementation of the malloc function in the C programming Language. This project was made to gain a better understanding of the C programming language and memory management

## Usage

The **lock.h** header file defines the following functions:

- To Allocate size bytes of uninitialized storage (melloc):

```c 
void *lock(size_t size);
```

- To Deallocates the space previously allocated (free)

```c 
void ze_hando(void *ptr);
```

- To Allocate memory for an array of num objects of size and initializes all bytes in the allocated storage to zero (realloc)

```c 
void *clock(size_t count, size_t size);
```

- Reallocates the given area of memory(calloc)

```c 
void relock(void *ptr, size_t size);
```
