/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** champion
*/

#pragma once

#include <stdbool.h>
#include "defs.h"
#include "command/defs.h"

/**
* @brief Create a new empty Champion.
*/
champion_t *champion_new(void);

/**
* @brief Free the given Champion.
* @param champions Champion to free
*/
void champion_free(champion_t *champion);

/**
* @brief Append a given command in a champions.
* @param champions Champion for append the command
* @param cmd Command to append
* @return true if the cmd is successfuly add, else false
*/
bool champion_append_cmd(champion_t *champion, cmd_t *cmd);
