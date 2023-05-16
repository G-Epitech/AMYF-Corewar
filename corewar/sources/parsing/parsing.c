/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** parsing
*/

#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include "parsing/parsing.h"
#include "common/include/op/defs.h"
#include "common/include/champion/champion.h"

champion_t *parsing_champion(char *file)
{
    champion_t *champion = champion_new();
    int fd = parsing_file_open(file);

    if (!champion || fd == -1)
        return NULL;
    parsing_header(champion, fd);
    return champion;
}
