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
#include "common/includes/utils/malloc2.h"
#include "common/includes/champion/champion.h"


static bool parsing_categorie(param_handler_t *params, char *args,
cmd_t **cmd, label_handler_t *label_handler)
{
    if (!parsing_argument_register(args, cmd, params))
        return false;
    if (!parsing_argument_number(args, cmd, params))
        return false;
    if (!parsing_argument_label(args, cmd, label_handler, params))
        return false;
    return true;
}

bool parsing_arguments(char **line_separed, cmd_t **cmd,
int *index_line, label_handler_t *label_handler)
{
    param_handler_t *params = malloc2(sizeof(param_handler_t));

    if (!params)
        return false;
    params->index_param = 0;
    params->status_param = false;
    while (line_separed[*index_line] != NULL) {
        if (params->index_param == 4)
            return false;
        if (!parsing_categorie(params, line_separed[*index_line],
        cmd, label_handler)) {
            return false;
        }
        params->status_param = false;
        params->index_param++;
        (*index_line)++;
    }
    return true;
}
