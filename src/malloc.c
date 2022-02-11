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
    PRINTF("MALLOC of size %ld\n", size);
    alloc_list_t *node = grab_existing_memory_chunk(alloc_list, size);
    if (node == NULL) {
        node = insert_alloc_node(&alloc_list, size, NULL);
    }
    PRINTF("MALLOC NODE %p => %p of size %ld\n", node, node->start, node->size);
    return (node->start);

}
