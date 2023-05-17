/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** param
*/

#include "parsing/parsing.h"
#include "common/includes/op/defs.h"
#include "common/includes/cmd/defs.h"

static void special_case_indexes(cmd_t *command, int *main_index, int fd,
int index)
{
    if (!IS_T_DIR(op_tab[command->index_cmd].type[index])) {
        command->parameters[index].value = parsing_read_short(fd);
        *main_index += 2;
    } else {
        command->parameters[index].value = parsing_read_int(fd);
        *main_index += 4;
    }
}

void parsing_get_params(cmd_t *command, int *main_index, int fd)
{
    int index = 0;

    while (command->parameters[index].type != 0) {
        if (command->parameters[index].type == P_REGISTER) {
            command->parameters[index].value = parsing_read_char(fd);
            *main_index += 1;
        }
        if (command->parameters[index].type == P_DIRECT)
            special_case_indexes(command, main_index, fd, index);
        if (command->parameters[index].type == P_INDIRECT) {
            command->parameters[index].value = parsing_read_short(fd);
            *main_index += 2;
        }
        index++;
    }
}
