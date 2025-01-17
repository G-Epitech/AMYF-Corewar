/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** body
*/

#include <stdbool.h>
#include "my/includes/my.h"
#include "parsing/parsing.h"
#include "common/includes/op/defs.h"
#include "common/includes/cmd/cmd.h"
#include "common/includes/node/node.h"
#include "common/includes/list/list.h"
#include "common/includes/champion/defs.h"

static void get_two_bits(int array[4], unsigned char declaration,
int *index)
{
    for (int j = 1; j < 4; j++) {
        if ((declaration & j) == j) {
            array[*index] = j;
            *index -= 1;
        }
    }
}

static void get_declaration(unsigned int *main_index, int fd, int array[4])
{
    char declaration = parsing_read_char(fd);
    int index = 3;

    *main_index += 1;
    for (int i = 0; i < 4; i++) {
        get_two_bits(array, declaration, &index);
        declaration >>= 2;
    }
}

static bool get_special_case(cmd_t *command, int fd, unsigned int *main_index)
{
    int index = command->index_cmd;

    if (op_tab[index].nbr_args > 1)
        return false;
    if (IS_T_DIR(op_tab[index].type[0])) {
        command->parameters[0].type = T_DIR;
        command->parameters[0].value = parsing_read_int(fd);
        *main_index += 4;
    }
    if (IS_T_IND(op_tab[index].type[0])) {
        command->parameters[0].type = T_IND;
        command->parameters[0].value = parsing_read_short(fd);
        *main_index += 2;
    }
    if (IS_T_REG(op_tab[index].type[0])) {
        command->parameters[0].type = T_REG;
        command->parameters[0].value = parsing_read_char(fd);
        *main_index += 1;
    }
    return true;
}

static node_t *get_cmd(unsigned int *main_index, int fd)
{
    char cmd_id = parsing_read_char(fd);
    int array[4];
    cmd_t *command = cmd_new();
    int index = 0;

    my_memset(array, 0, sizeof(int) * 4);
    *main_index += 1;
    command->index_cmd = cmd_id - 1;
    if (get_special_case(command, fd, main_index))
        return node_new(NODE_DATA_FROM_PTR(command));
    get_declaration(main_index, fd, array);
    for (int i = 0; i < 4; i++) {
        if (array[i] != 0) {
            command->parameters[index].type = array[i];
            index += 1;
        }
    }
    parsing_get_params(command, main_index, fd);
    return node_new(NODE_DATA_FROM_PTR(command));
}

bool parsing_body(champion_t *champion, int fd)
{
    unsigned int index = 0;
    node_t *pending = NULL;

    champion->body = list_new();
    if (!champion->body)
        return false;
    while (index < champion->header->body_size) {
        pending = get_cmd(&index, fd);
        if (!pending)
            return false;
        list_append(champion->body, pending);
    }
    return true;
}
