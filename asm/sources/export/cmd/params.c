/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** Corewar / Assembler / Export / Cmd / Prototype
*/

#include <unistd.h>
#include "export/export.h"
#include "my/includes/my.h"
#include "common/includes/op/defs.h"

static void asm_export_cmd_param_write(int value, char type, int file)
{
    REG_SIZE_TYPE reg = (REG_SIZE_TYPE) value;
    IND_SIZE_TYPE ind = (IND_SIZE_TYPE) value;
    DIR_SIZE_TYPE dir = (DIR_SIZE_TYPE) value;

    switch (type) {
        case T_REG:
            my_write_big_endian(file, &reg, REG_SIZE);
            break;
        case T_DIR:
            my_write_big_endian(file, &dir, DIR_SIZE);
            break;
        default:
            my_write_big_endian(file, &ind, IND_SIZE);
            break;
    }
}

static bool asm_export_cmd_param(cmd_t *cmd, int param_index, list_t *cmds,
int file)
{
    char allowed = op_tab[cmd->index_cmd].type[param_index];
    parameter_t *param = &(cmd->parameters[param_index]);
    char type = asm_export_cmd_get_type_of_param(param->type, allowed);
    int value = param->value;

    if (IS_T_LAB(param->type)) {
        if (!asm_export_get_labeled_param(param, cmd->body_pos,
            &value, cmds)) {
            return false;
        }
    }
    asm_export_cmd_param_write(value, type, file);
    return true;
}

bool asm_export_cmd_params(cmd_t *cmd, list_t *cmds, int file)
{
    bool success = true;
    int params_nb = (int) op_tab[cmd->index_cmd].nbr_args;

    for (int i = 0; i < params_nb; i++)
        success &= asm_export_cmd_param(cmd, i, cmds, file);
    return success;
}
