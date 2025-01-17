/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** List type remove and delete function
*/

#include <stdlib.h>
#include "list/list.h"
#include "node/node.h"

void list_remove(list_t *list, node_t *node)
{
    node_unlink(node);
    if (list->first == node)
        list->first = node->next;
    if (list->first)
        list->first->prev = NULL;
    if (list->last == node)
        list->last = node->prev;
    if (list->last)
        list->last->next = NULL;
    list->len--;
}

void list_delete(list_t *list, node_t *node, node_freer_t freer)
{
    list_remove(list, node);
    node_free(node, freer);
}
