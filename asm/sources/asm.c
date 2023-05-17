/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** asm
*/

#include <stdio.h>
#include "export/export.h"
#include "my/includes/my.h"
#include "parsing/parsing.h"
#include "common/includes/champion/champion.h"

int main(int argc, char **argv)
{
    champion_t * champion = parsing_champion(argc, argv);
    int status = 0;

    if (!champion)
        return 84;
    if (!asm_export_champion("out.cor", champion))
        status = 84;
    champion_free(champion);
    return 0;
}
