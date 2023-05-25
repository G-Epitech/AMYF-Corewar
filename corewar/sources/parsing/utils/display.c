/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** display
*/

#include "my/includes/my.h"
#include "common/includes/op/defs.h"
#include "common/includes/champion/champion.h"

static void display_header(champion_t *champion)
{
    my_printf("=== Champion ===\n");
    my_printf(" == Header ==\n");
    my_printf("Name: %s\n", champion->header->name);
    my_printf("Desciption: %s\n", champion->header->comment);
    my_printf("Body Size: %d\n", champion->header->body_size);
}

static void display_body(champion_t *champion)
{
    node_t *tmp = champion->body->first;
    cmd_t *cmd = NULL;

    my_printf(" == Body ==\n");
    while (tmp) {
        cmd = NODE_DATA_TO_PTR(tmp->data, cmd_t *);
        my_printf("Command: %s\n", op_tab[cmd->index_cmd].mnemonique);
        for (int i = 0; i < op_tab[cmd->index_cmd].nbr_args; i++) {
            my_printf("Param: [%d] %d\n", cmd->parameters[i].type,
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

void champion_fighter_display(champion_fighter_t *champion)
{
    if (!champion)
        return;
    if (champion->header)
        display_header((champion_t *)champion);
    my_printf(" == Registers ==\n");
    for (int i = 0; i < REG_NUMBER; i++)
        my_printf("Registre n°%d: [%d]\n", i, champion->registers[i]);
    my_printf("Cooldown: %d\n", champion->live);
    my_printf("Live: %d\n", champion->live);
    my_printf("PC: %d\n", champion->pc);
}
