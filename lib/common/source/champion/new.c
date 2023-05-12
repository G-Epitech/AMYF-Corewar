/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** new
*/

#include <unistd.h>
#include "utils/malloc2.h"
#include "champion/defs.h"

champion_t *champion_new(void)
{
    champion_t *champion = malloc2(sizeof(champion_t));

    if (!champion)
        return NULL;
    champion->header = NULL;
    champion->body = NULL;
    return champion;
}
