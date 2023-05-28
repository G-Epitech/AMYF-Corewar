/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** kill
*/

#include "my/includes/my.h"
#include "common/includes/list/list.h"
#include "common/includes/arena/defs.h"
#include "common/includes/champion/champion.h"

void corewar_kill_champion(arena_t *arena, node_t *node)
{
    champion_fighter_t *champion = NULL;

    champion = NODE_DATA_TO_PTR(node->data, champion_fighter_t *);
    if (!champion->live && arena->champions->len > 1)
        list_delete(arena->champions, node, &champion_fighter_node_free);
    else
        champion->live = false;
}
