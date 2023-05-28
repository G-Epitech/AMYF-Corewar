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

Test(execution, basic_with_flags, .init=redirect_all_stdout)
{
    arena_t *arena = NULL;
    int ac = 9;
    char *av[9] = {"corewar/corewar", "-a", "254", "../tests/utils/champions/bill.cor", "-n", "8", "../tests/utils/champions/pdf.cor", "-dump", "58"};

    arena = arena_init(ac, av);
    corewar_execute_arena(arena);
    arena_free(arena);
}

Test(execution, position_out_memory, .init=redirect_all_stdout)
{
    arena_t *arena = NULL;
    int ac = 9;
    char *av[9] = {"corewar/corewar", "-a", "254000", "../tests/utils/champions/bill.cor", "-n", "8", "../tests/utils/champions/pdf.cor", "-dump", "58"};

    arena = arena_init(ac, av);
    corewar_execute_arena(arena);
    arena_free(arena);
}

Test(execution, position_overlap, .init=redirect_all_stdout)
{
    arena_t *arena = NULL;
    int ac = 9;
    char *av[9] = {"corewar/corewar", "-a", "0", "../tests/utils/champions/bill.cor", "-a", "1", "../tests/utils/champions/pdf.cor", "-dump", "58"};

    arena = arena_init(ac, av);
    corewar_execute_arena(arena);
    arena_free(arena);
}

Test(execution, position_champions, .init=redirect_all_stdout)
{
    arena_t *arena = NULL;
    int ac = 9;
    char *av[9] = {"corewar/corewar", "-a", "0", "../tests/utils/champions/bill.cor", "", "", "../tests/utils/champions/pdf.cor", "-dump", "58"};

    arena = arena_init(ac, av);
    corewar_execute_arena(arena);
    arena_free(arena);
}

Test(execution, champions_number, .init=redirect_all_stdout)
{
    arena_t *arena = NULL;
    int ac = 7;
    char *av[7] = {"corewar/corewar", "-n", "2", "../tests/utils/champions/bill.cor", "../tests/utils/champions/pdf.cor", "-dump", "58"};

    arena = arena_init(ac, av);
    corewar_execute_arena(arena);
    arena_free(arena);
}


Test(execution, wrong_dump_flags, .init=redirect_all_stdout)
{
    int ac = 8;
    char *av[8] = {"corewar/corewar", "-a", "254", "../tests/utils/champions/bill.cor", "-n", "8", "../tests/utils/champions/pdf.cor", "-dump"};

    arena_init(ac, av);
}

Test(execution, wrong_flag, .init=redirect_all_stdout)
{
    arena_t *arena = NULL;
    int ac = 4;
    char *av[4] = {"corewar/corewar", "../tests/utils/champions/bill.cor", "-p", "../tests/utils/champions/pdd.cor"};

    arena = arena_init(ac, av);
    cr_assert_null(arena);
}

Test(execution, evil_file, .init=redirect_all_stdout)
{
    arena_t *arena = NULL;
    int ac = 3;
    char *av[3] = {"corewar/corewar", "../tests/utils/champions/42.cor", "../tests/utils/champions/pdd.cor"};

    arena = arena_init(ac, av);
    cr_assert_null(arena);
}

Test(execution, basic_all_cmd, .init=redirect_all_stdout)
{
    arena_t *arena = NULL;
    int ac = 3;
    char *av[3] = {"corewar/corewar", "../tests/utils/champions/pdf.cor", "../tests/utils/champions/all.cor"};

    arena = arena_init(ac, av);
    corewar_execute_arena(arena);
    arena_free(arena);
}

Test(execution_desassembler, basic, .init=redirect_all_stdout)
{
    corewar_dessassembler("../tests/utils/champions/42.cor");
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