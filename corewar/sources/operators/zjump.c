/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** zjump
*/

#include "arena/arena.h"
#include "my/includes/my.h"
#include "operators/defs.h"

bool corewar_operators_zjump(arena_t *arena, champion_fighter_t *champion,
parameter_t params[MAX_ARGS_NUMBER])
{
    int param = params[0].value;
    int pc = arena_get_real_addr((champion->pc + param % IDX_MOD) - 1);

    (void) arena;
    if (champion->carry == 1)
        champion->pc = pc;
    return true;
}
