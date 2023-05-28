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
    my_memset(arena->array, 0, sizeof(unsigned char) * MEM_SIZE);
    arena->champions = NULL;
    arena->cycle_to_die = CYCLE_TO_DIE;
    arena->nbr_live = 0;
    arena->total_cycle = 1;
    arena->dump = -1;
    arena->live_cycle = 0;
    arena->champions = NULL;
    arena->last = NULL;
    return arena;
}
