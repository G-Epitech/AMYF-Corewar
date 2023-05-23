/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** Corewar / Assembler / Export / Header: Export header of champion
*/

#include "export/export.h"

bool asm_export_champion_body(list_t *body, int file)
{
    bool success = true;
    node_t *node = body ? body->first : NULL;
    cmd_t *cmd = NULL;

    while (node && success) {
        cmd = NODE_DATA_TO_PTR(node->data, cmd_t *);
        if (cmd)
            success &= asm_export_cmd(cmd, body, file);
        node = node->next;
    }
    return success;
}
