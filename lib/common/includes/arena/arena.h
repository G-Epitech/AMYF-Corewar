/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** arena
*/

#pragma once

#include "defs.h"

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