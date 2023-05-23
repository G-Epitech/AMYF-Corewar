/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** new
*/

#include "utils/defs.h"
#include "common/includes/utils/malloc2.h"

utils_fighter_t *utils_fighter_new(void)
{
    utils_fighter_t *utils = malloc2(sizeof(utils_fighter_t));

    if (!utils)
        return NULL;
    utils->file = NULL;
    utils->load_address = -1;
    utils->prog_number = -1;
    utils->body = NULL;
    utils->body_size = 0;
    return utils;
}
