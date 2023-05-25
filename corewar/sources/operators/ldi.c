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
    int value = 0;

    if (!arena_get_val(&value, &(params[0]), champion, arena))
        return false;
    if (champion->carry == 1)
        champion->pc = (unsigned int) value;
    return true;
}
