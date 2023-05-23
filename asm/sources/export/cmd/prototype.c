/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** Corewar / Assembler / Export / Cmd / Prototype
*/

#include <unistd.h>
#include "export/export.h"
#include "common/includes/op/defs.h"

char asm_export_cmd_get_type_of_param(char types, char allowed)
{
    if (IS_T_VALID(types, allowed) && IS_T_DIR(types))
        return T_DIR;
    if (IS_T_VALID(types, allowed) && IS_T_REG(types))
        return T_REG;
    return T_IND;
}

static char asm_export_cmd_get_proto_of_param(char type)
{
    switch (type) {
        case T_DIR:
            return DIR_PROTO;
        case T_REG:
            return REG_PROTO;
        default:
            return IND_PROTO;
    }
}

bool asm_export_cmd_proto(cmd_t *cmd, int file)
{
    unsigned char prototype = T_NULL;
    bool prototype_needed = op_tab[cmd->index_cmd].proto;
    char *params_types = (char *) op_tab_health[cmd->index_cmd].type;
    int params_nb = (int) op_tab[cmd->index_cmd].nbr_args;
    char param_type = T_NULL;

    if (!prototype_needed)
        return false;
    for (int i = 0; i < 4; i++) {
        prototype <<= 2;
        if (i < params_nb) {
            param_type = asm_export_cmd_get_type_of_param(
            cmd->parameters[i].type, params_types[i]);
            prototype |= asm_export_cmd_get_proto_of_param(param_type);
        }
    }
    write(file, &prototype, sizeof(prototype));
    return true;
}
