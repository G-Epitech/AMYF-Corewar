/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** display
*/

#include <stdio.h>
#include "common/includes/champion/champion.h"

static void display_header(champion_t *champion)
{
    printf("=== Champion ===\n");
    printf(" == Header ==\n");
    printf("Name: %s\n", champion->header->name);
    printf("Desciption: %s\n", champion->header->comment);
    printf("Body Size: %ld\n", champion->header->body_size);
}

void parsing_display(champion_t *champion)
{
    if (!champion)
        return;
    if (champion->header)
        display_header(champion);
}
