// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	void *memory = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (memory == MAP_FAILED)
    return NULL;
    if (mem_list_add(memory, size) == -1){
        munmap(memory, size);
        return NULL;
    }
    return memory;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
    size_t total_size = nmemb * size;
	void *memory = mmap(NULL, total_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (memory == MAP_FAILED)
    return NULL;
    if (mem_list_add(memory, total_size) == -1) {
        munmap(memory, total_size);
        return NULL;
    }
    return memory;
}

void free(void *ptr)
{
     struct mem_list * iter = mem_list_find(ptr);
     if (iter == NULL)
     return;
     if (munmap(ptr, iter->len) == -1)
     return;
     if (mem_list_del(iter->start) == -1)
     return;
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
    struct mem_list *item = mem_list_find(ptr);
    if (item == NULL)
    return NULL;
    void *ptr1 = mremap(ptr, item->len, size, MREMAP_MAYMOVE);
    if (ptr1 == NULL)
    return NULL;
    item->len = size;
    return ptr1;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    struct mem_list *item = mem_list_find(ptr);
    if (item == NULL)
    return NULL;
    size_t totalsize = nmemb * size;
    void *ptr1 = mremap(ptr, item->len, totalsize, MREMAP_MAYMOVE);
    if (ptr1 == NULL)
    return NULL;
    item->len = totalsize;
    return ptr1;
}
