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
