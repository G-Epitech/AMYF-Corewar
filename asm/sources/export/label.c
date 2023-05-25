/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** Corewar / Assembler / Export / Label
*/

#include "export/export.h"

bool asm_export_get_labeled_param(parameter_t *param, unsigned int cmd_pos,
int *dist, list_t *cmds)
{
    cmd_t *target = asm_export_get_cmd_by_index(param->value, cmds);

    if (!target)
        return false;
    *dist = target->body_pos - cmd_pos;
    return true;
}
