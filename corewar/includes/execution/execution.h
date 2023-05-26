/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** execution
*/

#pragma once

#include "common/includes/arena/defs.h"
#include "common/includes/champion/defs.h"

/**
 * @brief Execute the whole arena.
 * @param arena Arena to execute
 */
void corewar_execute_arena(arena_t *arena);

/**
 * @brief Execute a champion.
 * @param arena Arena to execute the given champion
 * @param champion Champion to execute
 */
void corewar_execute_champion(arena_t *arena, champion_fighter_t *champion);

/**
 * @brief Kill a champion if it haven't say "live".
 * @param arena Arena to remove champion
 * @param node Node of the champion
 */
void corewar_kill_champion(arena_t *arena, node_t *node);

/**
 * @brief Read params and fill the array.
 * @param arena Arena to read commands
 * @param champion Champion to read command
 * @param parameters Parameters to fill with commands
 * @param cmd_index Index of the champion command
 */
void corewar_execute_champion_read_params(arena_t *arena,
champion_fighter_t *champion, parameter_t *parameters, int cmd_index);

/**
 * @brief Read int params champion.
 * @param arena Arena to read params
 * @param champion To read position (self updated)
 * @return Number size of int
 */
int corewar_execute_champion_read_int(arena_t *arena,
champion_fighter_t *champion);

/**
 * @brief Read short params champion.
 * @param arena Arena to read params
 * @param champion To read position (self updated)
 * @return Number size of short
 */
short corewar_execute_champion_read_short(arena_t *arena,
champion_fighter_t *champion);

/**
 * @brief Read char params champion.
 * @param arena Arena to read params
 * @param champion To read position (self updated)
 * @return Number size of char
 */
char corewar_execute_champion_read_char(arena_t *arena,
champion_fighter_t *champion);
