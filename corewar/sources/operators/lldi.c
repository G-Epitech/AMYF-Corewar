/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** ldi
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

bool corewar_operators_lldi(arena_t *arena, champion_fighter_t *champion,
parameter_t params[MAX_ARGS_NUMBER])
{
    int ind_size = 0;
    int addon = params[1].value;
    int reg_size = 0;
    int reg = params[2].value - 1;
    parameter_t sum = {
        .type = T_IND,
        .value = 0
    };

    if (!get_val(&ind_size, &(params[0]), champion, arena))
        return false;
    sum.value = ind_size + addon;
    if (!get_val(&reg_size, &(sum), champion, arena))
        return false;
    if (reg < 0 || reg >= REG_NUMBER)
        return false;
    champion->registers[params[2].value - 1] = reg_size;
    return true;
}
