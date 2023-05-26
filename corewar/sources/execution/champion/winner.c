/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** winner
*/

#include "my/includes/my.h"
#include "common/includes/arena/defs.h"
#include "common/includes/champion/defs.h"

static void display_winner(champion_fighter_t *champion)
{
    my_printf("The player %d(%s)has won.\n", champion->registers[0],
    champion->header->name);
}

bool corewar_execution_winner(arena_t *arena)
{
    node_t *node = arena->champions->first;
    champion_fighter_t *actual = NULL;
    champion_fighter_t *next = NULL;

    actual = NODE_DATA_TO_PTR(node->data, champion_fighter_t *);
    while (node->next) {
        actual = NODE_DATA_TO_PTR(node->data, champion_fighter_t *);
        next = NODE_DATA_TO_PTR(node->next->data, champion_fighter_t *);
        if (my_strcmp(actual->header->name, next->header->name) != 0)
            return false;
        node = node->next;
    }
    display_winner(actual);
    return true;
}
