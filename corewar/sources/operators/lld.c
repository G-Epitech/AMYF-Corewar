/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** live
*/

#include "arena/arena.h"
#include "my/includes/my.h"
#include "operators/defs.h"

static bool get_val(int *value, parameter_t *param,
champion_fighter_t *champion, arena_t *arena)
{
    int pval = param->value;
    short addr = 0;

    if (IS_T_REG(param->type)) {
        pval -= 1;
        if (pval < 0 || pval >= REG_NUMBER)
            return false;
        *value = champion->registers[pval];
        return true;
    }
    if (IS_T_IND(param->type)) {
        addr = arena_get_real_addr(champion->pc + pval);
        *value = arena->array[addr];
    } else {
        *value = pval;
    }
    return true;
}

bool corewar_operators_lld(arena_t *arena, champion_fighter_t *champion,
parameter_t params[MAX_ARGS_NUMBER])
{
    int reg = params[1].value - 1;
    int value = 0;

    if (reg < 0 || reg >= REG_NUMBER)
        return false;
    if (!get_val(&value, &(params[0]), champion, arena))
        return false;
    champion->registers[reg] = value;
    return true;
}
