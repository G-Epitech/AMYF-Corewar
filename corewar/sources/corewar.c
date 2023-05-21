/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** corewar
*/

#include "parsing/parsing.h"
#include "common/includes/champion/champion.h"

int main(int ac, char **av)
{
    champion_t *champion = parsing_champion(ac > 1 ? av[1] : NULL);

    parsing_display(champion);
    champion_free(champion);
    return 0;
}
