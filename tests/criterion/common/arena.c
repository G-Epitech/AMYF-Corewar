/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** arena
*/

#include <criterion/criterion.h>
#include "arena/arena.h"
#include "common/includes/utils/malloc2.h"

Test(arena_functions, new_arena)
{
    arena_t *arena = arena_new();

    cr_assert_not_null(arena);
    cr_assert_null(arena->champions);
    cr_assert(arena->nbr_live == 0);
    cr_assert(arena->total_cycle == 0);
    cr_assert(arena->cycle_to_die == CYCLE_TO_DIE);
    arena_free(arena);
}

Test(arena_functions, free_arena)
{
    arena_t *arena = arena_new();

    arena_free(arena);
}

Test(arena_functions, malloc_fail)
{
    arena_t *arena = NULL;

    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_FAIL);
    arena = arena_new();
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_NORMAL);
    cr_assert_null(arena);
    arena_free(arena);
}

Test(arena_functions, free_null)
{
    arena_free(NULL);
}
