/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** Corewar / Assembler / Export / Cmd
*/

#include <unistd.h>
#include "export/export.h"
#include "common/includes/op/defs.h"

bool asm_export_cmd(cmd_t *cmd, list_t *cmds, int file)
{
    if (!cmd || !cmds)
        return false;
    write(file, &(op_tab[cmd->index_cmd].code), OP_SIZE);
    asm_export_cmd_proto(cmd, file);
    return asm_export_cmd_params(cmd, cmds, file);
}
