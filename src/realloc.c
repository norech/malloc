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
    alloc_list_t *list = (alloc_list_t *)((byte_t *)ptr - HEADER_SIZE);

    if (ptr == NULL)
        return (malloc(size));
    if (list->size > size)
        return (ptr);
    new_ptr = malloc(size);
    memcpy(new_ptr, ptr, size);
    list->is_free = true;
    return (new_ptr);
}
