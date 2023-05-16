/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** corewar
*/

#include "parsing/parsing.h"
#include "common/include/champion/champion.h"

int main(int ac, char **av)
{
    if (!parsing_champion(ac > 1 ? av[1] : NULL))
        return 84;
    return 0;
}
