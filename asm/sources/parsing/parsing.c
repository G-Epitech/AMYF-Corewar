/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** asm parsing
*/

#include <stdio.h>
#include "parsing/parsing.h"
#include "common/includes/cmd/cmd.h"
#include "common/includes/header/header.h"
#include "common/includes/champion/champion.h"

champion_t *parse_champion(int argc, char **argv)
{
    champion_t *champion = NULL;
    file_t *file = NULL;
    char *input_champion = NULL;

    if (argc != 2)
        return NULL;
    champion = champion_new();
    if (!champion)
        return NULL;
    input_champion = parse_file(argv[1]);
    file = file_new(input_champion);
    champion->header = parsing_champion_header(file);
    if (champion->header == NULL)
        return NULL;
    champion->body = parsing_champion_body(input_champion, file);
    if (!champion->body)
        return NULL;
    return champion;
}