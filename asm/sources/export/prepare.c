/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** Corewar / Assembler / Export / Prepare
*/

#include <stdbool.h>
#include "export/export.h"
#include "common/includes/op/defs.h"
#include "common/includes/cmd/defs.h"
#include "common/includes/list/defs.h"
#include "common/includes/header/defs.h"

static bool asm_export_prepare_cmd(unsigned int size, cmd_t *cmd)
{
    if (!cmd)
        return false;
    if (cmd->label)
        cmd->body_pos = size + OP_SIZE;
    return true;
}

bool asm_export_prepare(header_t *header, list_t *commands)
{
    bool success = true;
    unsigned int size = 0;
    node_t *node = commands ? commands->first : NULL;
    cmd_t *cmd = NULL;

    if (!header)
        return false;
    while (node && success) {
        cmd = node ? NODE_DATA_TO_PTR(node->data, cmd_t *) : NULL;
        success &= asm_export_prepare_cmd(size, cmd);
        size += cmd ? asm_export_cmd_size_eval(cmd) : 0;
        node = node->next;
    }
    header->body_size = size;
    return success;
}
