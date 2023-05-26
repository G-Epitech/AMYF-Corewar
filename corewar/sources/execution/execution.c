/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** execution
*/

#include <stdbool.h>
#include "my/includes/my.h"
#include "execution/execution.h"
#include "operators/operators.h"
#include "common/includes/node/defs.h"
#include "common/includes/arena/defs.h"
#include "common/includes/champion/defs.h"

static void execute_pending_cmd(arena_t *arena, champion_fighter_t *champion)
{
    bool success = false;
    int index = champion->pending_cmd;
    unsigned int tmp_pc = 0;

    champion->pc -= champion->readed - 1;
    tmp_pc = champion->pc;
    success = operators_tab[index].func(arena, champion, champion->parameters);
    if (operators_tab[index].affect_carry)
        champion->carry = success;
    if (tmp_pc == champion->pc)
        champion->pc += champion->readed - 1;
    champion->readed = 0;
}

static void champion(arena_t *arena, node_t *tmp)
{
    champion_fighter_t *ch = NODE_DATA_TO_PTR(tmp->data, champion_fighter_t *);

    if (ch->cooldown > 0) {
        ch->cooldown -= 1;
        if (ch->cooldown == 1)
            execute_pending_cmd(arena, ch);
    } else {
        corewar_execute_champion(arena, ch);
    }
    if (arena->live_cycle == arena->cycle_to_die)
        corewar_kill_champion(arena, tmp);
}

static void update_variables(arena_t *arena)
{
    if (arena->live_cycle == arena->cycle_to_die)
        arena->live_cycle = 0;
    arena->total_cycle += 1;
    arena->live_cycle += 1;
    arena->nbr_live += 1;
}

void corewar_execute_arena(arena_t *arena)
{
    node_t *tmp = NULL;

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
        if (corewar_execution_winner(arena) ||
        arena->total_cycle == arena->dump) {
            break;
        }
        update_variables(arena);
    }
}
