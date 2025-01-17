/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** List type new function
*/

#include <stdlib.h>
#include "utils/malloc2.h"
#include "list/defs.h"

list_t *list_new(void)
{
    list_t *list = malloc2(sizeof(list_t));

    if (!list)
        return NULL;
    list->first = NULL;
    list->last = NULL;
    list->len = 0;
    return list;
}
