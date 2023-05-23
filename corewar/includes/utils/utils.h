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
 * @brief Sort an int array.
 * @param array Array to sort
 * @param size Size of the array
 */
void utils_array_sort(int array[], int size);

/**
 * @brief Display a fighter champion.
 * @param champion Champion to display
 */
void champion_fighter_display(champion_fighter_t *champion);
