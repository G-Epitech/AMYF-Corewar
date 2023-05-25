/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** free
*/

#include "cmd/cmd.h"
#include "list/list.h"
#include "champion/defs.h"
#include "header/header.h"

void champion_free(champion_t *champion)
{
    free(champion);
}

void champion_fighter_free(champion_fighter_t *champion)
{
    header_free(champion->header);
    list_free(champion->body, &cmd_node_freer);
    free(champion);
}
