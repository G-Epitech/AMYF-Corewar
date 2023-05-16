/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** asm parsing
*/

#include "parsing/parsing.h"
#include "common/include/cmd/cmd.h"
#include "common/include/header/header.h"
#include "common/include/champion/champion.h"

champion_t *parse_champion(int argc, char **argv)
{
    champion_t *champion = NULL;
    char *input_champion = NULL;

    if (argc != 2)
        return NULL;
    champion = champion_new();
    if (!champion)
        return NULL;
    input_champion = parse_file(argv[1]);
    champion->header = parsing_champion_header(input_champion);
    if (!champion->header)
        return NULL;
    champion->body = parsing_champion_body(input_champion);
    if (!champion->body)
        return NULL;
    return champion;
}
