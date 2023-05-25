/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** free
*/

#include <stdlib.h>
#include "cmd/defs.h"
#include "node/defs.h"

void cmd_free(cmd_t *cmd)
{
    if (!cmd)
        return;
    free(cmd);
}

void cmd_node_freer(node_data_t data)
{
    cmd_t *cmd = NODE_DATA_TO_PTR(data, cmd_t *);

    cmd_free(cmd);
}
