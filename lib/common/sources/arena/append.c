/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** append
*/

#include "list/list.h"
#include "node/node.h"
#include "arena/arena.h"
#include "champion/defs.h"

bool arena_append_champion(arena_t *arena, champion_fighter_t *champion)
{
    node_t *node = NULL;

    if (!arena || !arena->champions || !champion)
        return false;
    node = node_new(NODE_DATA_FROM_PTR(champion));
    if (!node)
        return false;
    list_append(arena->champions, node);
    return true;
}
