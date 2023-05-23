/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** arena
*/

#pragma once

#include <stdbool.h>
#include "utils/defs.h"
#include "common/includes/arena/defs.h"

/**
 * @brief Init arena with champions files.
 * @param ac Number of arguments
 * @param av Table of string with champions file names
 * @return Arena with champions write in
 */
arena_t *arena_init(int ac, char **av);

/**
 * @brief Parse User input in order to have champions with coreect options.
 * @param ac Number of args
 * @param av Table of args
 * @param utils Array of utils fighter
 * @return True if success or False if error found.
 */
bool arena_utils_init(int ac, char **av, utils_fighter_t *utils[4]);

/**
 * @brief Fill arena with champion body.
 * @param arena Arena to fill
 * @param utils Utils with champions fighter
 */
void arena_init_champion_position(arena_t *arena, utils_fighter_t *utils[4]);
