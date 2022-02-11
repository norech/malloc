/*
** EPITECH PROJECT, 2022
** malloc
** File description:
** free
*/
#include "allocate_memory.h"
#include "alloc_free.h"
#include "alignment.h"
#include "debug.h"

void free(void *ptr)
{
    alloc_list_t *node = (alloc_list_t *)((byte_t *)ptr - HEADER_SIZE);
    if (ptr == NULL)
        return;
    PRINTF("FREE NODE-1 %p\n", node);
    PRINTF("FREE NODE %p => %p\n", node, node->start);
    free_alloc_node(node);
}
