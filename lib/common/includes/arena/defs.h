/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** defs
*/

#pragma once

#include "../op/defs.h"
#include "../list/defs.h"

#define NBR_LIVE 40
#define CYCLE_DELTA 5
#define CYCLE_TO_DIE 1536
#define MEM_SIZE (6 * 1024)

// Represente an arena
typedef struct s_arena {
    unsigned char array[MEM_SIZE];  // Array of the Arena
    int cycle_to_die;               // Number of cycle availaible to say “live”
    int total_cycle;               // Total cycle done
    int nbr_live;                   // Reduce cycle_to_die with cycle_delta
    list_t *champions;              // List of champions in the Arena
} arena_t;
