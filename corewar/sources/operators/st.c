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

    if (reg < 0 || reg >= REG_NUMBER)
        return false;
    if (!arena_get_val(&value, &(params[1]), champion, arena))
        return false;
    champion->registers[reg] = value;
}
