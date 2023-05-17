/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** display
*/

#include <stdio.h>
#include "common/includes/op/defs.h"
#include "common/includes/champion/champion.h"

static void display_header(champion_t *champion)
{
    printf("=== Champion ===\n");
    printf(" == Header ==\n");
    printf("Name: %s\n", champion->header->name);
    printf("Desciption: %s\n", champion->header->comment);
    printf("Body Size: %ld\n", champion->header->body_size);
}

static void display_body(champion_t *champion)
{
    node_t *tmp = champion->body->first;
    cmd_t *cmd = NULL;

    printf(" == Body ==\n");
    while (tmp) {
        cmd = NODE_DATA_TO_PTR(tmp->data, cmd_t *);
        printf("Command: %s\n", op_tab[cmd->index_cmd].mnemonique);
        for (int i = 0; i < op_tab[cmd->index_cmd].nbr_args; i++) {
            printf("Param: [%d] %d\n", cmd->parameters[i].type,
            cmd->parameters[i].value);
        }
        tmp = tmp->next;
    }
}

void parsing_display(champion_t *champion)
{
    if (!champion)
        return;
    if (champion->header)
        display_header(champion);
    if (champion->body)
        display_body(champion);
}
