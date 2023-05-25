/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** live
*/

#include "arena/arena.h"
#include "my/includes/my.h"
#include "operators/defs.h"

bool corewar_operators_ld(arena_t *arena, champion_fighter_t *champion,
parameter_t params[MAX_ARGS_NUMBER])
{
    int reg = params[1].value - 1;
    int value = 0;

    if (reg < 0 || reg >= REG_NUMBER)
        return false;
    if (!arena_get_val(&value, &(params[0]), champion, arena))
        return false;
    champion->registers[reg] = value;
    return true;
}
