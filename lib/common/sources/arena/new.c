/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** new
*/

#include "arena/defs.h"
#include "utils/malloc2.h"
#include "my/includes/my.h"

arena_t *arena_new(void)
{
    arena_t *arena = malloc2(sizeof(arena_t));

    if (!arena)
        return NULL;
    my_memset(arena->array, 0, MEM_SIZE);
    arena->champions = NULL;
    arena->cycle_to_die = 0;
    arena->nbr_live = 0;
    arena->total_cycle = 0;
    return arena;
}