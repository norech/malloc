/*
** EPITECH PROJECT, 2022
** malloc
** File description:
** reallocarray
*/

#include <stddef.h>
#include <stdlib.h>

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    size_t total = nmemb * size;

    if (nmemb == 0 || size == 0)
        return (NULL);
    if (ptr == NULL)
        return (malloc(total));
    return (realloc(ptr, total));
}
