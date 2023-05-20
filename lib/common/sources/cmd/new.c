/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** new
*/
#include <stdio.h>
#include <stdlib.h>
#include "cmd/defs.h"
#include "utils/malloc2.h"
#include "my/includes/my.h"
#include "common/includes/op/defs.h"

int find_instruction(char *instruction)
{
    for (int index = 0; op_tab[index].mnemonique != 0; index++) {
        if (my_strcmp(op_tab[index].mnemonique, instruction) == 0) {
            return index;
        }
    }
    return -1;
}

cmd_t *cmd_new(char *instruction)
{
    cmd_t *cmd = malloc2(sizeof(cmd_t));
    int index_instruction = 0;

    if (!cmd)
        return NULL;
    cmd->label = NULL;
    for (size_t i = 0; i < MAX_ARGS_NUMBER; i++) {
        cmd->parameters[i].type = P_NULL;
        cmd->parameters[i].value = 0;
    }
    index_instruction = find_instruction(instruction);
    if (index_instruction == -1)
        return NULL;
    cmd->index_cmd = index_instruction;
    return cmd;
}
