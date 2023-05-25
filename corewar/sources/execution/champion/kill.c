/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** kill
*/

#include "my/includes/my.h"
#include "common/includes/list/list.h"
#include "common/includes/arena/defs.h"
#include "common/includes/champion/defs.h"

void corewar_kill_champion(arena_t *arena, node_t *node)
{
    champion_fighter_t *champion = NULL;

    champion = NODE_DATA_TO_PTR(node->data, champion_fighter_t *);
    if (!champion->live)
        list_remove(arena->champions, node);
}
