/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** live
*/

#include "my/includes/my.h"
#include "operators/defs.h"

bool corewar_operators_live(arena_t *arena, champion_fighter_t *champion,
parameter_t params[MAX_ARGS_NUMBER])
{
    (void) arena;
    champion->live = true;
    my_printf("The player %d(%s)is alive.\n", params[0].value,
    champion->header->name);
    return true;
}
