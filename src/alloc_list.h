/*
** EPITECH PROJECT, 2022
** malloc
** File description:
** alloc_list
*/

#pragma once

#include <stddef.h>
#include <stdbool.h>

typedef unsigned char byte_t;

typedef struct alloc_list_s {
    struct alloc_list_s *next;
    struct alloc_list_s *prev;
    size_t size;
    void *start;
    bool is_free;
} alloc_list_t;

alloc_list_t *insert_alloc_node(alloc_list_t **list, size_t size, void *start);

void remove_alloc_node(alloc_list_t **list, alloc_list_t *node);

alloc_list_t *find_alloc_node(alloc_list_t *list, void *addr, bool ignore_free);

alloc_list_t *grab_existing_memory_chunk(alloc_list_t *list, size_t size);

void free_alloc_node(alloc_list_t *node);
