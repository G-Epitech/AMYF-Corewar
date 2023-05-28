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
#include "execution/execution.h"
#include "common/includes/arena/arena.h"
#include "common/includes/champion/champion.h"

static void display_arena_line(int line)
{
    char *hexa = "0123456789ABCDEF";
    int len = 0;

    if (line == MEM_SIZE)
        return;
    len = my_putnbr_base(line, hexa);
    while (len < 5) {
        my_putchar(' ');
        len += 1;
    }
    my_putstr(" : ");
}

static void display_arena(arena_t *arena)
{
    char *hexa = "0123456789ABCDEF";
    int break_line = 0;
    int line = 0;

    my_putstr("0    : ");
    for (int i = 0; i < MEM_SIZE; i++) {
        if (my_putnbr_base_len(arena->array[i], hexa) < 3)
            my_putchar('0');
        my_putnbr_base(arena->array[i], hexa);
        break_line += 1;
        if (break_line == 32) {
            my_putchar('\n');
            line += 32;
            display_arena_line(line);
            break_line = 0;
        } else {
            my_putchar(' ');
        }
    }
}

int main(int ac, char **av)
{
    arena_t *arena = NULL;

    if (ac == 3 && my_strcmp(av[1], "-d") == 0)
        return corewar_dessassembler(av[2]);
    arena = arena_init(ac, av);
    corewar_execute_arena(arena);
    if (arena->dump > 0)
        display_arena(arena);
    arena_free(arena);
    return 0;
}
