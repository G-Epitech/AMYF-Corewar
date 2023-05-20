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

bool parsing_argument_number(char *args, cmd_t **cmd,
param_handler_t *params)
{
    int value = 0;

    if (params->status_param == true || my_strstr(args, ":") != NULL)
        return true;
    if (args[0] == '%') {
        args++;
        (*cmd)->parameters[params->index_param].type = P_DIRECT;
    } else {
        (*cmd)->parameters[params->index_param].type = P_INDIRECT;
    }
    if (my_str_isnum(args) == 0)
        return false;
    value = my_getnbr(args);
    (*cmd)->parameters[params->index_param].value = value;
    params->status_param = true;
    return true;
}
