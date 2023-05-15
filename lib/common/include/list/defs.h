/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** defs
*/

#pragma once

#include <stdlib.h>
#include "../node/defs.h"

// Represent linked list
typedef struct s_list {
    node_t *first;  //First node of list
    node_t *last;   //Last node of list
    size_t len;     //Length of list
} list_t;
