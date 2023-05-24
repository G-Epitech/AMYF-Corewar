/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** execution
*/

#include <stdbool.h>
#include "execution/execution.h"
#include "common/includes/node/defs.h"
#include "common/includes/arena/defs.h"
#include "common/includes/champion/defs.h"

static void champion(arena_t *arena, node_t *tmp)
{
    champion_fighter_t *ch = NODE_DATA_TO_PTR(tmp->data, champion_fighter_t *);

    corewar_execute_champion(arena, ch);
    if (arena->live_cycle == arena->cycle_to_die)
        corewar_kill_champion(arena, tmp);
}

void corewar_execute_arena(arena_t *arena)
{
    node_t *tmp = NULL;
    int temp_dump = 20;

    while (true) {
        tmp = arena->champions->first;
        while (tmp) {
            champion(arena, tmp);
            tmp = tmp->next;
        }
        if (arena->nbr_live == NBR_LIVE) {
            arena->cycle_to_die -= CYCLE_DELTA;
            arena->nbr_live = 0;
        }
        if (arena->champions->len == 1 || arena->total_cycle > temp_dump)
            break;
        arena->total_cycle += 1;
        arena->nbr_live += 1;
    }
}
