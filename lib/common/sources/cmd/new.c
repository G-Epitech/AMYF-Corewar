/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** new
*/

#include <stdlib.h>
#include "op/defs.h"
#include "cmd/defs.h"
#include "utils/malloc2.h"
#include "my/includes/my.h"
#include "common/includes/op/defs.h"

cmd_t *cmd_new(void)
{
    cmd_t *cmd = malloc2(sizeof(cmd_t));

    if (!cmd)
        return NULL;
    cmd->label = NULL;
    cmd->index_cmd = 0;
    cmd->body_pos = 0;
    for (size_t i = 0; i < MAX_ARGS_NUMBER; i++) {
        cmd->parameters[i].type = T_NULL;
        cmd->parameters[i].value = 0;
    }
    return cmd;
}
