/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** ldi
*/

#include "arena/arena.h"
#include "my/includes/my.h"
#include "operators/defs.h"

bool corewar_operators_ldi(arena_t *arena, champion_fighter_t *champion,
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

    if (!arena_get_val(&ind_size, &(params[0]), champion, arena))
        return false;
    sum.value = ind_size + addon;
    if (!arena_get_val(&reg_size, &(sum), champion, arena))
        return false;
    if (reg < 0 || reg >= REG_NUMBER)
        return false;
    champion->registers[params[2].value - 1] = reg_size;
    return true;
}
