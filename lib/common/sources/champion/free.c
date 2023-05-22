/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** free
*/

#include "champion/defs.h"

void champion_free(champion_t *champion)
{
    if (!champion)
        return;
    free(champion);
}

void champion_fighter_free(champion_fighter_t *champion)
{
    if (!champion)
        return;
    free(champion);
}
