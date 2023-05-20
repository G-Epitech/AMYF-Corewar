/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** asm parsing body
*/

#include "parsing/utils.h"
#include "my/includes/my.h"
#include "parsing/parsing.h"
#include "common/includes/op/defs.h"
#include "common/includes/cmd/cmd.h"
#include "common/includes/list/list.h"
#include "common/includes/header/header.h"
#include "common/includes/champion/champion.h"

static int get_index_label_cmd(char *name_label,
label_handler_t *label_handler)
{
    node_t *temp = label_handler->labels->first;

    while (temp) {
        if (my_strcmp(NODE_DATA_TO_PTR(temp->data, label_t *)->name,
        name_label) == 0) {
            return NODE_DATA_TO_PTR(temp->data, label_t *)->line;
        }
        temp = temp->next;
    }
    return -1;
}

bool parsing_argument_label(char *args, cmd_t **cmd,
label_handler_t *label_handler, param_handler_t *params)
{
    int index_cmd_label = -1;

    if (params->status_param == true || my_strstr(args, ":") == NULL)
        return true;
    if (args[0] == '%') {
        args++;
        (*cmd)->parameters[params->index_param].type = P_DIRECT | T_LAB;
    } else {
        (*cmd)->parameters[params->index_param].type = P_INDIRECT | T_LAB;
    }
    args++;
    index_cmd_label = get_index_label_cmd(args, label_handler);
    if (index_cmd_label == -1)
        return false;
    (*cmd)->parameters[params->index_param].value = index_cmd_label;
    params->status_param = true;
    return true;
}
