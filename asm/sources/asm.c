/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** asm
*/

#include <stdio.h>
#include "parsing/utils.h"
#include "export/export.h"
#include "parsing/parsing.h"
#include "common/includes/champion/champion.h"

int main(int argc, char **argv)
{
    champion_t * champion = parsing_champion(argc, argv);

    if (!champion)
        return 84;
    asm_export_champion("out.cor", champion);
    champion_free(champion);
    return 0;
}
