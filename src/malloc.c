/*
** EPITECH PROJECT, 2022
** malloc
** File description:
** malloc
*/

#include <string.h>
#include <unistd.h>

void *malloc(size_t size)
{
    return (sbrk(size));
}
