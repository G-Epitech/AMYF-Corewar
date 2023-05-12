/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** append_parameter
*/

#include <stdlib.h>
#include <stdbool.h>
#include "cmd/defs.h"

bool cmd_append_parameter(cmd_t *cmd, parameter_t parameter)
{
    if (!cmd)
        return false;
    for (size_t i = 0; i < MAX_ARGS_NUMBER; i++) {
        if (cmd->parameters[i].type == P_NULL)
            continue;
        cmd->parameters[i] = parameter;
        return true;
    }
    return false;
}
