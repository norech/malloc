/*
** EPITECH PROJECT, 2022
** malloc
** File description:
** alignment
*/

#include <stddef.h>
#include "alloc_list.h"

size_t nearest_pow_of_2(size_t size)
{
    return 1 << (32 - __builtin_clz(size - 1));
}

size_t get_aligned_size(size_t size)
{
    return nearest_pow_of_2(size);
}
