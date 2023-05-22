/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** asm parsing body
*/

#include "parsing/utils.h"
#include "my/includes/my.h"
#include "parsing/parsing.h"
#include "common/includes/cmd/cmd.h"
#include "common/includes/list/list.h"
#include "common/includes/header/header.h"
#include "common/includes/utils/malloc2.h"
#include "common/includes/champion/champion.h"

bool parsing_body_label_check_existing(label_handler_t *handler,
char *new_label)
{
    node_t *temp = handler->labels->first;

    while (temp) {
        if (my_strcmp(NODE_DATA_TO_PTR(temp->data, label_t *)->name,
        new_label) == 0) {
            return false;
        }
        temp = temp->next;
    }
    return true;
}
