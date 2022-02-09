/*
** EPITECH PROJECT, 2022
** malloc
** File description:
** malloc
*/

#include <string.h>
#include "allocate_memory.h"

void *malloc(size_t size)
{
    return (grow_allocated_memory(size));
}
