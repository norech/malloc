/*
** EPITECH PROJECT, 2022
** malloc
** File description:
** alloc_free
*/

#pragma once

#include "alloc_list.h"

void free_alloc_node(alloc_list_t *node);

alloc_list_t *find_free_node(alloc_list_t *list, size_t size);
