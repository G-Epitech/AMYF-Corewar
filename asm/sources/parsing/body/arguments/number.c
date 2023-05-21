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

static bool arguments_direct(cmd_t **cmd, param_handler_t *params)
{
    if (!IS_T_DIR(op_tab_health[(*cmd)->index_cmd].type[params->index_param]))
        return false;
    (*cmd)->parameters[params->index_param].type = T_DIR;
    return true;
}

static bool arguments_indirect(cmd_t **cmd, param_handler_t *params)
{
    if (!IS_T_IND(op_tab_health[(*cmd)->index_cmd].type[params->index_param]))
        return false;
    (*cmd)->parameters[params->index_param].type = T_IND;
    return true;
}

bool parsing_argument_number(char *args, cmd_t **cmd,
param_handler_t *params)
{
    int value = 0;

    if (params->status_param == true || my_strstr(args, ":") != NULL)
        return true;
    if (args[0] == '%') {
        args++;
        if (!arguments_direct(cmd, params))
            return false;
    } else {
        if (!arguments_indirect(cmd, params))
            return false;
    }
    if (my_str_isnum(args) == 0)
        return false;
    value = my_getnbr(args);
    (*cmd)->parameters[params->index_param].value = value;
    params->status_param = true;
    return true;
}
