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
 * @return true if the function success
 */
bool corewar_operators_live(champion_fighter_t *champion, cmd_t *command);

static const operator_t operators_tab[] = {
    NULL
};
