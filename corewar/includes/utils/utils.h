/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** utils
*/

#pragma once

#include "defs.h"
#include "common/includes/champion/defs.h"

/**
 * @brief Create a new utils.
 * @return New empty utils
 */
utils_fighter_t *utils_fighter_new(void);

/**
 * @brief Free utils fighter.
 * @param utils Utils to free
 */
void utils_fighter_free(utils_fighter_t *utils);

/**
 * @brief Sort utils array.
 * @param utils Array utils to sort
 */
void utils_array_sort(utils_fighter_t *utils[4]);

/**
 * @brief Display a fighter champion.
 * @param champion Champion to display
 */
void champion_fighter_display(champion_fighter_t *champion);
