/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** live
*/

#include "arena/arena.h"
#include "my/includes/my.h"
#include "operators/defs.h"

bool corewar_operators_aff(arena_t *arena, champion_fighter_t *champion,
parameter_t params[MAX_ARGS_NUMBER])
{
    int value = 0;

    if (!arena_get_val(&value, &(params[0]), champion, arena))
        return false;
    if (value == 42) {
        my_putchar('*');
    } else {
        value %= 256;
        my_put_nbr(value);
    }
    return true;
}
