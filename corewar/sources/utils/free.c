/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** free
*/

#include <stdlib.h>
#include "utils/defs.h"

void utils_fighter_free(utils_fighter_t *utils)
{
    if (!utils)
        return;
    free(utils->file);
    free(utils->body);
    free(utils);
}
