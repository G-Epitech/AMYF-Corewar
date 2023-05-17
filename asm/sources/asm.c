/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** asm
*/

#include "export/export.h"
#include "common/includes/champion/champion.h"

int main(void)
{
    champion_t *champion = champion_new();

    asm_export_champion("out.cor", champion);
    champion_free(champion);
    return 0;
}
