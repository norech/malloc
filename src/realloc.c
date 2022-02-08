/*
** EPITECH PROJECT, 2022
** malloc
** File description:
** realloc
*/

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

void *realloc(void *ptr, size_t size)
{
    void *new_ptr = malloc(size);

    if (new_ptr == NULL)
        return (NULL);
    if (ptr == NULL)
        return (new_ptr);
    memcpy(new_ptr, ptr, size);
    free(ptr);
    return (new_ptr);
}
