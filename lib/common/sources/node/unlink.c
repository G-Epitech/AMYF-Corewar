/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** Node type unlink function
*/

#include "node/defs.h"

void node_unlink(node_t *node)
{
    if (node->next)
        node->next->prev = node->prev;
    if (node->prev)
        node->prev->next = node->next;
}
