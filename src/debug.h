/*
** EPITECH PROJECT, 2022
** malloc
** File description:
** debug
*/

#pragma once

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#ifdef DEBUG
    static char str__[1024];

    #define PRINTF(...)                                                      \
        sprintf(str__, __VA_ARGS__);                                         \
        write(1, str__, strlen(str__));
#else
    #define PRINTF(...) (void)0
#endif
