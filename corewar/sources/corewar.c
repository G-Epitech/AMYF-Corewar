/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** corewar
*/

#include <stdio.h>
#include "arena/arena.h"
#include "utils/utils.h"
#include "common/includes/champion/champion.h"

static void display_arena_champions(arena_t *arena)
{
    node_t *tmp = arena->champions->first;
    champion_fighter_t *champion = NULL;

    while (tmp) {
        champion = NODE_DATA_TO_PTR(tmp->data, champion_fighter_t *);
        champion_fighter_display(champion);
        tmp = tmp->next;
    }
}

int main(int ac, char **av)
{
    arena_t *arena = NULL;

    arena = arena_init(ac, av);
    display_arena_champions(arena);
    (void)arena;
    return 0;
}
