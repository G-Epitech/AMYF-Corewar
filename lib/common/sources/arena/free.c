/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** free
*/

#include <stdlib.h>
#include "list/list.h"
#include "arena/defs.h"
#include "champion/champion.h"

void arena_free(arena_t *arena)
{
    if (!arena)
        return;
    list_free(arena->champions, &champion_fighter_node_free);
    free(arena);
}
