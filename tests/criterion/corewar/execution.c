/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** execution
*/

#include <criterion/criterion.h>
#include "arena/arena.h"
#include "execution/execution.h"

Test(execution, basic)
{
    arena_t *arena = NULL;
    int ac = 3;
    char *av[3] = {"corewar/corewar", "tests/utils/champions/bill.cor", "tests/utils/champions/pdf.cor"};

    arena = arena_init(ac, av);
    corewar_execute_arena(arena);
}
