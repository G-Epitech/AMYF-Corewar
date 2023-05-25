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

typedef bool (*operator_t)(arena_t *arena,
champion_fighter_t *champion, parameter_t params[MAX_ARGS_NUMBER]);
