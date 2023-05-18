/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** parsing
*/

#include "parsing/parsing.h"
#include "common/includes/champion/champion.h"

champion_t *parsing_champion(char *file)
{
    champion_t *champion = champion_new();
    int fd = parsing_file_open(file);

    if (!champion || fd == -1)
        return NULL;
    if (!parsing_header(champion, fd)) {
        champion_free(champion);
        return NULL;
    }
    if (!parsing_body(champion, fd)) {
        champion_free(champion);
        return NULL;
    }
    return champion;
}
