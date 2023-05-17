/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** asm
*/

#include <stdio.h>
#include "my/includes/my.h"
#include "parsing/utils.h"
#include "parsing/parsing.h"
#include "common/includes/champion/champion.h"

int main(int argc, char **argv)
{
    champion_t * champion = parse_champion(argc, argv);

    (void) champion;
}
