/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** operators
*/

#pragma once

#include "defs.h"
#include "common/includes/cmd/defs.h"
#include "common/includes/champion/defs.h"

/**
 * @brief Operator of corewar (live).
 * @param champion Champion that use this operator
 * @param command Specific command structure of the operator
 * @return true if the function success, false otherwise
 */
bool corewar_operators_live(arena_t *arena, champion_fighter_t *champion,
parameter_t params[MAX_ARGS_NUMBER]);

/**
 * @brief Operator of corewar (ld).
 * @param champion Champion that use this operator
 * @param command Specific command structure of the operator
 * @return true if the function success, false otherwise
 */
bool corewar_operators_ld(arena_t *arena, champion_fighter_t *champion,
parameter_t params[MAX_ARGS_NUMBER]);

/**
 * @brief Operator of corewar (st).
 * @param champion Champion that use this operator
 * @param command Specific command structure of the operator
 * @return true if the function success, false otherwise
 */
bool corewar_operators_st(arena_t *arena, champion_fighter_t *champion,
parameter_t params[MAX_ARGS_NUMBER]);

static const operator_t operators_tab[] = {
    &corewar_operators_live,
    &corewar_operators_ld,
    &corewar_operators_st,
    NULL
};