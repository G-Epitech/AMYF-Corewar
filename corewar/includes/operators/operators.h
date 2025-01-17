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

/**
 * @brief Operator of corewar (or).
 * @param champion Champion that use this operator
 * @param command Specific command structure of the operator
 * @return true if the function success, false otherwise
 */
bool corewar_operators_or(arena_t *arena, champion_fighter_t *champion,
parameter_t params[MAX_ARGS_NUMBER]);

/**
 * @brief Operator of corewar (xor).
 * @param champion Champion that use this operator
 * @param command Specific command structure of the operator
 * @return true if the function success, false otherwise
 */
bool corewar_operators_xor(arena_t *arena, champion_fighter_t *champion,
parameter_t params[MAX_ARGS_NUMBER]);

/**
 * @brief Operator of corewar (lldi).
 * @param champion Champion that use this operator
 * @param command Specific command structure of the operator
 * @return true if the function success, false otherwise
 */
bool corewar_operators_lldi(arena_t *arena, champion_fighter_t *champion,
parameter_t params[MAX_ARGS_NUMBER]);

/**
 * @brief Operator of corewar (lld).
 * @param champion Champion that use this operator
 * @param command Specific command structure of the operator
 * @return true if the function success, false otherwise
 */
bool corewar_operators_lld(arena_t *arena, champion_fighter_t *champion,
parameter_t params[MAX_ARGS_NUMBER]);

/**
 * @brief Operator of corewar (aff).
 * @param champion Champion that use this operator
 * @param command Specific command structure of the operator
 * @return true if the function success, false otherwise
 */
bool corewar_operators_aff(arena_t *arena, champion_fighter_t *champion,
parameter_t params[MAX_ARGS_NUMBER]);

/**
 * @brief Operator of corewar (sti).
 * @param champion Champion that use this operator
 * @param command Specific command structure of the operator
 * @return true if the function success, false otherwise
 */
bool corewar_operators_sti(arena_t *arena, champion_fighter_t *champion,
parameter_t params[MAX_ARGS_NUMBER]);

/**
 * @brief Operator of corewar (fork).
 * @param champion Champion that use this operator
 * @param command Specific command structure of the operator
 * @return true if the function success, false otherwise
 */
bool corewar_operators_fork(arena_t *arena, champion_fighter_t *champion,
parameter_t params[MAX_ARGS_NUMBER]);

/**
 * @brief Operator of corewar (lfork).
 * @param champion Champion that use this operator
 * @param command Specific command structure of the operator
 * @return true if the function success, false otherwise
 */
bool corewar_operators_lfork(arena_t *arena, champion_fighter_t *champion,
parameter_t params[MAX_ARGS_NUMBER]);

static const operator_t operators_tab[] = {
    {&corewar_operators_live, false},
    {&corewar_operators_ld, true},
    {&corewar_operators_st, false},
    {&corewar_operators_add, true},
    {&corewar_operators_sub, true},
    {&corewar_operators_and, true},
    {&corewar_operators_or, true},
    {&corewar_operators_xor, true},
    {&corewar_operators_zjump, false},
    {&corewar_operators_ldi, true},
    {&corewar_operators_sti, false},
    {&corewar_operators_fork, false},
    {&corewar_operators_lld, true},
    {&corewar_operators_lldi, true},
    {&corewar_operators_lfork, false},
    {&corewar_operators_aff, false},
    {NULL, false}
};
