/*
** EPITECH PROJECT, 2022
** malloc
** File description:
** realloc
*/

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "alignment.h"
#include "alloc_list.h"

void *realloc(void *ptr, size_t size)
{
    byte_t *new_ptr;
    alloc_list_t *block = (alloc_list_t *)((byte_t *)ptr
        - sizeof(alloc_list_t));

    if (ptr == NULL)
        return (malloc(size));
    if (block->size >= size)
        return (ptr);
    new_ptr = malloc(size);
    if (new_ptr == NULL)
        return (ptr);
    memcpy(new_ptr, ptr, block->size);
    block->is_free = true;
    return (new_ptr);
}
