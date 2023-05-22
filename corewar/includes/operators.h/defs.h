/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** defs
*/

#pragma once

#include "common/includes/cmd/defs.h"
#include "common/includes/champion/defs.h"

typedef int (*operator_t)(champion_fighter_t *champion, cmd_t *command);

static const operator_t operators_tab[] = {
    NULL
};
