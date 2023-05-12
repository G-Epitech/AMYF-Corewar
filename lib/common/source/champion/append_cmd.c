/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** append_cmd
*/

#include <stdbool.h>
#include "list/list.h"
#include "node/node.h"
#include "command/defs.h"
#include "champion/defs.h"

bool champion_append_cmd(champion_t *champion, cmd_t *cmd)
{
    node_t *node = NULL;

    if (!champion || !cmd || !champion->body)
        return false;
    node = node_new(NODE_DATA_FROM_PTR(cmd));
    if (!node)
        return false;
    list_append(champion->body, node);
    return false;
}
