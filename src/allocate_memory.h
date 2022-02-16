/*
** EPITECH PROJECT, 2022
** malloc
** File description:
** allocate_memory
*/

#pragma once

#include <stddef.h>
#include <unistd.h>
#include "alloc_list.h"

typedef struct allocator_s {
    void *last_ptr_pos;
    size_t last_ptr_size;
    void *page_start;
    void *page_end;
    void *pages_origin;
    alloc_list_t *list;
} allocator_t;

#define PAGE_SIZE ((size_t)getpagesize() * 2)

// requests a chunk of specified size at the end of the virtual heap
// if not enough memory is in the heap, allocates 2 new pages
//
// returns a pointer to the start position of the last chunk of memory
// (allocated end - size)
void *grow_allocated_memory(size_t size);

// releases a chunk of specied size at the end of the virtual heap
// if a page size ends up empty, it is deallocated
void shrink_allocated_memory(size_t size);

allocator_t *get_allocator(void);
