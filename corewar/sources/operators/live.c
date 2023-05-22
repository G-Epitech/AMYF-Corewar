/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** live
*/

#include "my/includes/my.h"
#include "common/includes/cmd/defs.h"
#include "common/includes/champion/defs.h"

bool corewar_operators_live(champion_fighter_t *champion, cmd_t *command)
{
    champion->live = true;
    my_printf("The player %d(%s)is alive.\n", command->parameters[0].value,
    champion->header->name);
    return true;
}
