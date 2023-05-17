/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** asm
*/

#include "export/export.h"
#include "my/includes/my.h"
#include "common/includes/header/header.h"
#include "common/includes/champion/champion.h"

int main(void)
{
    champion_t *champion = champion_new();

    champion->header = header_new();
    my_strcpy(champion->header->name, "Bill");
    my_strcpy(champion->header->comment, "Equilibre");
    asm_export_champion("out.cor", champion);
    champion_free(champion);
    return 0;
}
