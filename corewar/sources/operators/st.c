/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** live
*/

#include "arena/arena.h"
#include "my/includes/my.h"
#include "operators/defs.h"

bool corewar_operators_st(arena_t *arena, champion_fighter_t *champion,
parameter_t params[MAX_ARGS_NUMBER])
{
    int reg = params[0].value - 1;
    int value = 0;
    short addr = 0;

    if (reg < 0 || reg >= REG_NUMBER)
        return false;
    if (IS_T_REG(params[1].type)) {
        value = champion->registers[params[1].value];
    } else {
        addr = arena_get_real_addr(champion->pc + params[1].value % IDX_MOD);
        value = arena->array[addr];
    }
    champion->registers[reg] = value;
}
