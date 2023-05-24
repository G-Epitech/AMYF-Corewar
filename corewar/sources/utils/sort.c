/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** sort
*/

#include <stdlib.h>
#include "utils/defs.h"

static void swap_number(utils_fighter_t *utils[4], int j)
{
    utils_fighter_t *temp = NULL;

    if (utils[j]->prog_number > utils[j + 1]->prog_number) {
        temp = utils[j];
        utils[j] = utils[j + 1];
        utils[j + 1] = temp;
    }
}

void utils_array_sort(utils_fighter_t *utils[4])
{
    int size = 4;

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++)
            swap_number(utils, j);
    }
}
