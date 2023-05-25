/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** defs
*/

#pragma once

#include "common/includes/cmd/defs.h"
#include "common/includes/arena/defs.h"
#include "common/includes/champion/defs.h"

typedef bool (*operator_func_t)(arena_t *arena,
champion_fighter_t *champion, parameter_t params[MAX_ARGS_NUMBER]);

typedef struct s_operator {
    operator_func_t func;
    bool affect_carry;
} operator_t;
