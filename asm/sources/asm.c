/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** asm
*/

#include <stdio.h>
#include "parsing/parsing.h"
#include "common/include/champion/champion.h"

int main(int argc, char **argv)
{
    champion_t * champion = parse_champion(argc, argv);

    if (!champion) {
        printf("There is an error : 84\n");
    }
}
