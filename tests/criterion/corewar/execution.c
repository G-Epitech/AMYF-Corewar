/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** execution
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "arena/arena.h"
#include "execution/execution.h"
#include "common/includes/arena/arena.h"

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(execution, basic, .init=redirect_all_stdout)
{
    arena_t *arena = NULL;
    int ac = 3;
    char *av[3] = {"corewar/corewar", "../tests/utils/champions/bill.cor", "../tests/utils/champions/pdf.cor"};

    arena = arena_init(ac, av);
    corewar_execute_arena(arena);
    arena_free(arena);
}

Test(execution, winner, .init=redirect_all_stdout)
{
    arena_t *arena = NULL;
    int ac = 3;
    char *av[3] = {"corewar/corewar", "../tests/utils/champions/bill.cor", "../tests/utils/champions/pdf.cor"};

    arena = arena_init(ac, av);
    corewar_kill_champion(arena, arena->champions->first->next);
    arena->last = NODE_DATA_TO_PTR(arena->champions->first->data, champion_fighter_t *);
    cr_assert(corewar_execution_winner(arena) == true);
    arena_free(arena);
}

Test(execution, no_winner, .init=redirect_all_stdout)
{
    arena_t *arena = NULL;
    int ac = 3;
    char *av[3] = {"corewar/corewar", "../tests/utils/champions/bill.cor", "../tests/utils/champions/pdf.cor"};

    arena = arena_init(ac, av);
    cr_assert(corewar_execution_winner(arena) == false);
    arena_free(arena);
}

Test(execution, same_winner, .init=redirect_all_stdout)
{
    arena_t *arena = NULL;
    int ac = 3;
    char *av[3] = {"corewar/corewar", "../tests/utils/champions/bill.cor", "../tests/utils/champions/bill.cor"};

    arena = arena_init(ac, av);
    arena->last = NODE_DATA_TO_PTR(arena->champions->first->data, champion_fighter_t *);
    cr_assert(corewar_execution_winner(arena) == true);
    arena_free(arena);
}