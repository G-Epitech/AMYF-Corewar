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

static bool check_param(parameter_t *param, int index_cmd)
{
    int nb_args = 0;

    while (param->type != P_NULL) {
        // if (param[nb_args].type != op_tab_health[index_cmd].type[nb_args])
        printf("type type : [%i]\n", op_tab_health[index_cmd].type[nb_args]);
        nb_args++;
    }
    printf("\n");
    return true;
}

bool parsing_check_wrong_param(champion_t *champion)
{
    node_t *temp = champion->body->first;
    int index_cmd = 0;

    while (temp) {
        index_cmd = NODE_DATA_TO_PTR(temp->data, cmd_t *)->index_cmd;
        if (!check_param(NODE_DATA_TO_PTR(temp->data, cmd_t *)->parameters,
        index_cmd)) {
            return false;
        }
        temp = temp->next;
    }
}
