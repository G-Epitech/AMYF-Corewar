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

/**
 * @brief Operator of corewar (add).
 * @param champion Champion that use this operator
 * @param command Specific command structure of the operator
 * @return true if the function success, false otherwise
 */
bool corewar_operators_add(arena_t *arena, champion_fighter_t *champion,
parameter_t params[MAX_ARGS_NUMBER]);

/**
 * @brief Operator of corewar (sub).
 * @param champion Champion that use this operator
 * @param command Specific command structure of the operator
 * @return true if the function success, false otherwise
 */
bool corewar_operators_sub(arena_t *arena, champion_fighter_t *champion,
parameter_t params[MAX_ARGS_NUMBER]);

/**
 * @brief Operator of corewar (zjump).
 * @param champion Champion that use this operator
 * @param command Specific command structure of the operator
 * @return true if the function success, false otherwise
 */
bool corewar_operators_zjump(arena_t *arena, champion_fighter_t *champion,
parameter_t params[MAX_ARGS_NUMBER]);

/**
 * @brief Operator of corewar (ldi).
 * @param champion Champion that use this operator
 * @param command Specific command structure of the operator
 * @return true if the function success, false otherwise
 */
bool corewar_operators_ldi(arena_t *arena, champion_fighter_t *champion,
parameter_t params[MAX_ARGS_NUMBER]);

/**
 * @brief Operator of corewar (and).
 * @param champion Champion that use this operator
 * @param command Specific command structure of the operator
 * @return true if the function success, false otherwise
 */
bool corewar_operators_and(arena_t *arena, champion_fighter_t *champion,
parameter_t params[MAX_ARGS_NUMBER]);

static const operator_t operators_tab[] = {
    &corewar_operators_live,
    &corewar_operators_ld,
    &corewar_operators_st,
    &corewar_operators_add,
    &corewar_operators_sub,
    &corewar_operators_and,
    &corewar_operators_zjump,
    &corewar_operators_ldi,
    NULL
};
