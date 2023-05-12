/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** new
*/

#include <stdlib.h>
#include "cmd/defs.h"
#include "utils/malloc2.h"

cmd_t *cmd_new(char *command)
{
    cmd_t *cmd = malloc2(sizeof(cmd_t));

    if (!cmd)
        return NULL;
    cmd->label = NULL;
    for (size_t i = 0; i < MAX_ARGS_NUMBER; i++)
        cmd->parameters[i].type = P_NULL;
    return cmd;
}
