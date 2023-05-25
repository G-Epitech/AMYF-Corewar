/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** address
*/

#include "common/includes/arena/defs.h"
#include "common/includes/champion/defs.h"

short arena_get_real_addr(int addr)
{
    short diff = addr % MEM_SIZE;

    return (diff >= 0 ? diff : (MEM_SIZE + diff));
}

bool arena_get_val(int *value, parameter_t *param,
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
        addr = arena_get_real_addr(champion->pc + pval % IDX_MOD);
        *value = arena->array[addr];
    } else {
        *value = pval;
    }
    return true;
}
