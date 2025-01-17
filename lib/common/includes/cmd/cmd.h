/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** cmd
*/

#pragma once

#include <stdbool.h>
#include "defs.h"
#include "../node/node.h"

/**
* @brief Create a new cmd for a Champion.
* The index_cmd is instantly refer to the command name in the array.
*/
cmd_t *cmd_new(void);

/**
* @brief Free the given command Champion.
* @param cmd Command to free
*/
void cmd_free(cmd_t *cmd);

/**
 * @brief Free node cmd in a list.
 * @param data Node data to free
 */
void cmd_node_freer(node_data_t data);

/**
* @brief Append a given parameter in a command.
* @param cmd Command for append parameter
* @param parameter Parameter to append
* @return true if success else false
*/
bool cmd_append_parameter(cmd_t *cmd, parameter_t parameter);
