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
    node_t *node = arena->champions->first;
    champion_fighter_t *tmp = NULL;
    bool say = false;

    (void)champion;
    while (node) {
        tmp = NODE_DATA_TO_PTR(node->data, champion_fighter_t *);
        if (params[0].value == tmp->registers[0]) {
            tmp->live = true;
            arena->last = tmp;
            say = true;
            break;
        }
        node = node->next;
    }
    if (say) {
        my_printf("The player %d(%s)is alive.\n", params[0].value,
        arena->last->header->name);
    }
    return true;
}
