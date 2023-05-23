/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** new
*/

#include "utils/malloc2.h"
#include "champion/defs.h"
#include "my/includes/my.h"

champion_t *champion_new(void)
{
    champion_t *champion = malloc2(sizeof(champion_t));

    if (!champion)
        return NULL;
    champion->header = NULL;
    champion->body = NULL;
    return champion;
}

champion_fighter_t *champion_fighter_new(void)
{
    champion_fighter_t *champion = malloc2(sizeof(champion_fighter_t));

    if (!champion)
        return NULL;
    champion->pc = 0;
    champion->cooldown = 0;
    champion->live = false;
    champion->header = NULL;
    champion->body = NULL;
    champion->body_size = 0;
    my_memset(champion->registers, 0, REG_NUMBER);
    return champion;
}
