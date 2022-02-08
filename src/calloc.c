/*
** EPITECH PROJECT, 2022
** malloc
** File description:
** calloc
*/

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

void *calloc(size_t nmemb, size_t size)
{
    size_t total = nmemb * size;
    void *ptr = malloc(total);

    if (ptr == NULL)
        return (NULL);
    memset(ptr, 0, total);
    return (ptr);
}
