/*
** EPITECH PROJECT, 2022
** malloc
** File description:
** alloc_list
*/

#include "debug.h"
#include "alloc_list.h"
#include "alloc_free.h"
#include "alignment.h"
#include "allocate_memory.h"

alloc_list_t *insert_alloc_node(alloc_list_t **list, size_t size, void *start)
{
    PRINTF("INSERT NEW NODE of size %ld at %p\n", size, start);
    alloc_list_t *node = (start == NULL)
        ? grow_allocated_memory(HEADER_SIZE + get_aligned_size(size))
        : start;
    if (node == NULL)
        return (NULL);
    node->next = *list;
    node->prev = NULL;
    node->size = get_aligned_size(size);
    node->start = (byte_t *)node + HEADER_SIZE;
    if (*list != NULL)
        (*list)->prev = node;
    *list = node;
    return (node);
}

alloc_list_t *find_alloc_node(alloc_list_t *list, void *addr, bool ignore_free)
{
    alloc_list_t *node = list;
    PRINTF("FIND ALLOC\n");

    while (node != NULL) {
        PRINTF("node->start = %p\n", node->start);
        if ((void *)node >= addr && node->start + node->size <= addr
            && (!ignore_free || !node->is_free))
                return (node);
        node = node->next;
    }
    return (NULL);
}

void split_memory_chunk(alloc_list_t *node, size_t required_size)
{
    alloc_list_t *new_node;
    PRINTF("SPLIT NODE %p => %p (%ld)\n", node, node->start, node->size);
    new_node = (alloc_list_t *)((byte_t *)node->start + required_size);
    new_node->next = node->next;
    new_node->prev = node;
    new_node->size = node->size - required_size - HEADER_SIZE;
    new_node->start = new_node + HEADER_SIZE;
    new_node->is_free = true;
    if (node->next != NULL)
        node->next->prev = new_node;
    node->next = new_node;
    node->size = required_size;

}

void merge_memory_chunk(alloc_list_t *node)
{
    PRINTF("MERGE CHUNKS\n");
    while (node->next != NULL && node->next->is_free) {
        node->size += node->next->size + sizeof(alloc_list_t);
        node->next = node->next->next;
        if (node->next != NULL)
            node->next->prev = node;
    }
}

alloc_list_t *grab_existing_memory_chunk(alloc_list_t *list, size_t size)
{
    alloc_list_t *node = find_free_node(list, size);

    PRINTF("GRAB EXISTING FREE NODE %p\n", node);
    if (node == NULL) {
        PRINTF(" no free node found\n");
        return (NULL);
    }
    PRINTF(" size %ld -> %p (%s)\n", node->size, node->start,
        node->is_free ? "free" : "used");
    node->is_free = false;
    return (node);

}
