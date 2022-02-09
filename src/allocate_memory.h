/*
** EPITECH PROJECT, 2022
** malloc
** File description:
** allocate_memory
*/

#pragma once

#include <stddef.h>
#include <unistd.h>

#define PAGE_SIZE (getpagesize() * 2)

// requests a chunk of specified size at the end of the virtual heap
// if not enough memory is in the heap, allocates 2 new pages
//
// returns a pointer to the start position of the last chunk of memory
// (allocated end - size)
void *grow_allocated_memory(size_t size);

// releases a chunk of specied size at the end of the virtual heap
// if a page size ends up empty, it is deallocated
void shrink_allocated_memory(size_t size);

// get the pointer to the start of the virtual heap
void *get_allocated_start(void);

// get the pointer to the end of the virtual heap
void *get_allocated_end(void);
