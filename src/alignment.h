/*
** EPITECH PROJECT, 2022
** malloc
** File description:
** alignment
*/

#pragma once

#include <stddef.h>

size_t get_aligned_size(size_t size);

#define HEADER_SIZE get_aligned_size(sizeof(alloc_list_t))
