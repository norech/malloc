/*
** EPITECH PROJECT, 2022
** malloc
** File description:
** allocate_memory
*/

#include "allocate_memory.h"
#include "debug.h"

static void *last_ptr_pos = NULL;
static size_t last_ptr_size = 0;
static void *page_start = NULL;
static void *page_end = NULL;
static void *pages_origin = NULL;

void *grow_allocated_memory_large(size_t size)
{
    void *page_start_large = grow_allocated_memory(PAGE_SIZE);

    size -= PAGE_SIZE;
    while (size > PAGE_SIZE) {
        grow_allocated_memory(PAGE_SIZE);
        size -= PAGE_SIZE;
    }
    grow_allocated_memory(size);
    return (page_start_large);
}

void *grow_allocated_memory(size_t size)
{
    PRINTF("GROW to size %ld\n", size);
    if (page_end == NULL || last_ptr_pos + last_ptr_size + size > page_end) {
        if (size > PAGE_SIZE)
            return (grow_allocated_memory_large(size));
        page_start = sbrk(PAGE_SIZE);
        page_end = sbrk(0);
        if (page_start == NULL || page_end == NULL)
            return (NULL);
        if (pages_origin == NULL)
            pages_origin = page_start;
        last_ptr_pos = page_start;
        last_ptr_size = size;
        return (last_ptr_pos);
    }
    last_ptr_pos += last_ptr_size;
    last_ptr_size = size;
    return (last_ptr_pos);
}

void shrink_allocated_memory(size_t size)
{
    if (page_start == NULL)
        return;
    if (last_ptr_pos - size < page_start) {
        page_end = sbrk(0);
        page_start = sbrk(-PAGE_SIZE);
    }
    size -= last_ptr_size;
    last_ptr_size = 0;
    last_ptr_pos -= size;
    if (last_ptr_pos < pages_origin)
        last_ptr_pos = pages_origin;
}

void *get_allocated_start(void)
{
    return (pages_origin);
}

void *get_allocated_end(void)
{
    return (last_ptr_pos + last_ptr_size);
}
