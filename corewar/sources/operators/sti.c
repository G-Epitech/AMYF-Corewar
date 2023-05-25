/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** sti
*/

#include "arena/arena.h"
#include "my/includes/my.h"
#include "operators/defs.h"

static bool add_valude(char type, int value, champion_fighter_t *champion,
int *addition)
{
    int pval = 0;

    if (IS_T_REG(type)) {
        pval = value - 1;
        if (pval < 0 || pval >= REG_NUMBER)
            return false;
        (*addition) += champion->registers[pval];
    } else {
        (*addition) += value;
    }
    return true;
}

bool corewar_operators_sti(arena_t *arena, champion_fighter_t *champion,
parameter_t params[MAX_ARGS_NUMBER])
{
    int register_index = params[0].value - 1;
    int register_value = champion->registers[register_index];
    int addition = 0;
    int address = 0;
    int pval = 0;

    if (!add_valude(params[1].type, params[1].value, champion, &addition))
        return false;
    if (!add_valude(params[2].type, params[2].value, champion, &addition))
        return false;
    address = arena_get_real_addr(champion->pc + addition % IDX_MOD);
    return false;
}
