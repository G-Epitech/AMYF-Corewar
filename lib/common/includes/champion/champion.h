/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** champion
*/

#pragma once

#include <stdbool.h>
#include "defs.h"
#include "../cmd/defs.h"

/**
* @brief Create a new empty champion.
*/
champion_t *champion_new(void);

/**
* @brief Free the given champion.
* @param champions Champion to free
*/
void champion_free(champion_t *champion);

/**
* @brief Append a given command in a champion.
* @param champions Champion in which append the command
* @param cmd Command to append
* @return true if the command is successfuly added, else false
*/
bool champion_append_cmd(champion_t *champion, cmd_t *cmd);
