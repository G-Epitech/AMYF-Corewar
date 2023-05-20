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

bool parsing_argument_register(char *args, cmd_t **cmd,
param_handler_t *params)
{
    int register_id = 0;

    if (args[0] != 'r')
        return true;
    (*cmd)->parameters[params->index_param].type = T_REG;
    args++;
    if (my_str_isnum(args) == 0)
        return false;
    register_id = my_getnbr(args);
    if (register_id > REG_NUMBER)
        return false;
    (*cmd)->parameters[params->index_param].value = register_id;
    params->status_param = true;
    return true;
}
