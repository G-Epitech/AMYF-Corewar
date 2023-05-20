/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** asm
*/

#include <stdio.h>
#include "parsing/utils.h"
#include "export/export.h"
#include "my/includes/my.h"
#include "parsing/parsing.h"
#include "common/includes/champion/champion.h"

int main(int argc, char **argv)
{
    champion_t * champion = parsing_champion(argc, argv);

    if (!champion)
        return 84;


    node_t *temp = champion->body->first;

    while (temp) {
        printf("Index cmd : [%i] | [%s] label of cmd\n", NODE_DATA_TO_PTR(temp->data, cmd_t *)->index_cmd, NODE_DATA_TO_PTR(temp->data, cmd_t *)->label);
        for (int index = 0; index < 4; index++) {
            printf("\tparametre type: [%i] | [%i] valeur parametre\n", NODE_DATA_TO_PTR(temp->data, cmd_t *)->parameters[index].type, NODE_DATA_TO_PTR(temp->data, cmd_t *)->parameters[index].value);
        }
        printf("\n\n");
        temp = temp->next;
    }
    asm_export_champion("out.cor", champion);
    champion_free(champion);
    return 0;
}
