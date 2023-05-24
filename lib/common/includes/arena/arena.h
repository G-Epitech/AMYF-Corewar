/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** arena
*/

#pragma once

#include "defs.h"
#include "../champion/defs.h"

/**
 * @brief Create a new arena.
 * @return New empty arena
 */
arena_t *arena_new(void);

/**
* @brief Free the given arena.
* @param arena Arena to free
*/
void arena_free(arena_t *arena);

/**
 * @brief Append a champion in the list Arena.
 * @param arena Arena to append champion
 * @param champion Champion to append to arena
 * @return true on success or false if error
 */
bool arena_append_champion(arena_t *arena, champion_fighter_t *champion);
