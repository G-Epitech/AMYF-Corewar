/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** free
*/

#include <stdlib.h>
#include "arena/defs.h"

void arena_free(arena_t *arena)
{
    free(arena);
}
