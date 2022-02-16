/*
** EPITECH PROJECT, 2022
** malloc
** File description:
** malloc
*/

#include <string.h>
#include "alloc_free.h"
#include "alloc_list.h"
#include "allocate_memory.h"
#include "debug.h"

void *malloc(size_t size)
{
    alloc_list_t *node;
    allocator_t *alloc = get_allocator();
    PRINTF("MALLOC of size %ld\n", size);
    node = grab_existing_memory_chunk(alloc->list, size);
    if (node == NULL) {
        node = insert_alloc_node(&alloc->list, size, NULL);
    }
    PRINTF("MALLOC NODE %p => %p of size %ld\n", node, node->start, node->size);
    return (node->start);

}
