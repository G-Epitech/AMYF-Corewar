/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** Corewar / Assembler / Export / Size: Compute size in real writing time
*/

#include <stdio.h>
#include "common/includes/op/defs.h"
#include "common/includes/cmd/defs.h"

int asm_export_cmd_size_get_proto(cmd_t *cmd)
{
    if (op_tab[cmd->index_cmd].nbr_args <= 1)
        return 0;
    return PROTO_SIZE;
}

char asm_export_cmd_size_get_param(char type, char allowed)
{
    if (IS_T_VALID(type, allowed) && IS_T_DIR(type))
        return DIR_SIZE;
    if (IS_T_VALID(type, allowed) && IS_T_REG(type))
        return REG_SIZE;
    return IND_SIZE;
}

int asm_export_cmd_size_get_params(cmd_t *cmd)
{
    int size = 0;
    char *params_types = (char *) op_tab[cmd->index_cmd].type;
    int params_nb = (int) op_tab[cmd->index_cmd].nbr_args;

    for (int i = 0; i < params_nb; i++) {
        size += asm_export_cmd_size_get_param(
            cmd->parameters[i].type,
            params_types[i]
        );
    } c
    return size;
}

int asm_export_cmd_size_eval(cmd_t *cmd)
{
    int size = OP_SIZE;

    size += asm_export_cmd_size_get_proto(cmd);
    size += asm_export_cmd_size_get_params(cmd);
    return size;
}
