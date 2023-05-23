/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** corewar
*/

#include <stdio.h>
#include "arena/arena.h"
#include "utils/utils.h"
#include "my/includes/my.h"
#include "common/includes/champion/champion.h"

static void display_arena(arena_t *arena)
{
    node_t *tmp = arena->champions->first;
    champion_fighter_t *champion = NULL;
    int break_line = 0;
    char *hexa = "0123456789ABCDEF";

    while (tmp) {
        champion = NODE_DATA_TO_PTR(tmp->data, champion_fighter_t *);
        champion_fighter_display(champion);
        tmp = tmp->next;
    }
    for (int i = 0; i < MEM_SIZE; i++) {
        if (my_putnbr_base_len(arena->array[i], hexa) < 3)
            my_putchar('0');
        my_putnbr_base(arena->array[i], hexa);
        break_line += 1;
        if (break_line == 32) {
            my_putchar('\n');
            break_line = 0;
        } else {
            my_putchar(' ');
        }
    }
}

int main(int ac, char **av)
{
    arena_t *arena = NULL;

    arena = arena_init(ac, av);
    display_arena(arena);
    return 0;
}
