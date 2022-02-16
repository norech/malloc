/*
** EPITECH PROJECT, 2022
** malloc
** File description:
** allocate_memory
*/

#include "allocate_memory.h"
#include "debug.h"

allocator_t *get_allocator(void)
{
    static allocator_t alloc = {
        .last_ptr_pos = (void *)-1,
        .last_ptr_size = 0,
        .page_start = (void *)-1,
        .page_end = (void *)-1,
        .pages_origin = (void *)-1,
        .list = NULL
    };

    return &alloc;
}

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
    allocator_t *alloc = get_allocator();
    PRINTF("GROW to size %ld\n", size);
    if (alloc->page_end == (void *)-1
        || alloc->last_ptr_pos + alloc->last_ptr_size + size
        > alloc->page_end) {
        if (size > PAGE_SIZE)
            return (grow_allocated_memory_large(size));
        alloc->page_start = sbrk(PAGE_SIZE);
        alloc->page_end = sbrk(0);
        if (alloc->page_start == (void *)-1 || alloc->page_end == (void *)-1)
            return (NULL);
        if (alloc->pages_origin == (void *)-1)
            alloc->pages_origin = alloc->page_start;
        alloc->last_ptr_pos = alloc->page_start;
        alloc->last_ptr_size = size;
        return (alloc->last_ptr_pos);
    }
    alloc->last_ptr_pos += alloc->last_ptr_size;
    alloc->last_ptr_size = size;
    return (alloc->last_ptr_pos);
}

void shrink_allocated_memory(size_t size)
{
    allocator_t *alloc = get_allocator();
    if (alloc->page_start == (void *)-1)
        return;
    if (alloc->last_ptr_pos - size < alloc->page_start) {
        alloc->page_end = sbrk(0);
        alloc->page_start = sbrk(-PAGE_SIZE);
    }
    size -= alloc->last_ptr_size;
    alloc->last_ptr_size = 0;
    alloc->last_ptr_pos -= size;
    if (alloc->last_ptr_pos < alloc->pages_origin)
        alloc->last_ptr_pos = alloc->pages_origin;
}
