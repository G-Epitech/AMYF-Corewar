/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** Corewar / Assembler / Export / Cmd / Get by index
*/

#include "export/export.h"

cmd_t *asm_export_get_cmd_by_index(int index, list_t *cmds)
{
    int i = 0;
    node_t *node = cmds ? cmds->first : NULL;

    while (i < index && node) {
        node = node->next;
        i += 1;
    }
    return node ? NODE_DATA_TO_PTR(node->data, cmd_t *) : NULL;
}
