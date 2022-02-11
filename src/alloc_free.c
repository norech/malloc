/*
** EPITECH PROJECT, 2022
** malloc
** File description:
** alloc_free
*/

#include "alloc_list.h"
#include "alloc_free.h"
#include "allocate_memory.h"

void free_alloc_node(alloc_list_t *node)
{
    node->is_free = true;
}

alloc_list_t *find_free_node(alloc_list_t *list, size_t size)
{
    alloc_list_t *node = list;

    while (node != NULL) {
        if (node->is_free && node->size >= size)
            return (node);
        node = node->next;
    }
    return (NULL);
}
