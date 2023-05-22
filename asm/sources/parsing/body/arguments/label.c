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

static bool handler_label_direct(char **args,
cmd_t **cmd, param_handler_t *params)
{
    (*args)++;
    if (!IS_T_DIR(op_tab_health[(*cmd)->index_cmd].type[params->index_param]))
        return false;
    (*cmd)->parameters[params->index_param].type = T_DIR | T_LAB;
    return true;
}

static bool handler_label_indirect(cmd_t **cmd, param_handler_t *params)
{
    if (!IS_T_IND(op_tab_health[(*cmd)->index_cmd].type[params->index_param]))
        return false;
    (*cmd)->parameters[params->index_param].type = T_IND | T_LAB;
    return true;
}

bool parsing_argument_label(char *args, cmd_t **cmd,
label_handler_t *label_handler, param_handler_t *params)
{
    int index_cmd_label = -1;

    if (params->status_param == true || my_strstr(args, ":") == NULL)
        return true;
    if (args[0] == '%') {
        if (!handler_label_direct(&args, cmd, params))
            return false;
    } else {
        if (!handler_label_indirect(cmd, params))
            return false;
    }
    args++;
    index_cmd_label = get_index_label_cmd(args, label_handler);
    if (index_cmd_label == -1)
        return false;
    (*cmd)->parameters[params->index_param].value = index_cmd_label;
    params->status_param = true;
    return true;
}
