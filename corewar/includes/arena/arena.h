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
#include "common/includes/champion/defs.h"

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
 * @return true if success or false if error found.
 */
bool arena_utils_init(int ac, char **av, utils_fighter_t *utils[4]);

/**
 * @brief Fill arena with champion body.
 * @param arena Arena to fill
 * @param utils Utils with champions fighter
 */
void arena_init_champion_position(arena_t *arena, utils_fighter_t *utils[4]);

/**
 * @brief Compute real address of given address.
 * @param addr Address to compute
 * @return Computed address
 */
short arena_get_real_addr(int addr);

/**
 * @brief Get value from memory depeding on parameter type.
 * @param value Variable in which store value
 * @param param Parameter on which base recuperation
 * @param champion Champion object
 * @param arena Arena object
 * @return Status of getting
 */
bool arena_get_val(int *value, parameter_t *param,
champion_fighter_t *champion, arena_t *arena);
