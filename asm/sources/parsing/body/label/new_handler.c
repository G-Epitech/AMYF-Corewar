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
#include "common/includes/node/node.h"
#include "common/includes/header/header.h"
#include "common/includes/utils/malloc2.h"
#include "common/includes/champion/champion.h"

label_t *label_new(void)
{
    label_t *new = malloc2(sizeof(label_t));

    if (!new)
        return NULL;
    new->name = NULL;
    new->line = 0;
    return new;
}

bool label_append(list_t *list_labels, label_t *label)
{
    node_t *node = NULL;

    if (!list_labels || !label)
        return false;
    node = node_new(NODE_DATA_FROM_PTR(label));
    if (!node)
        return false;
    list_append(list_labels, node);
    return true;
}

label_handler_t *label_handler_new(void)
{
    label_handler_t *new = malloc2(sizeof(label_handler_t));

    if (!new)
        return NULL;
    new->labels = list_new();
    if (!new->labels)
        return NULL;
    new->line_parsing = 0;
    new->index_cmd = 0;
    new->status_label = true;
    return new;
}
