/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** asm parsing header
*/

#include "parsing/parsing.h"
#include "parsing/utils.h"
#include "common/include/cmd/cmd.h"
#include "common/include/header/header.h"
#include "common/include/champion/champion.h"

header_t *parsing_champion_header(char *input_champion, file_t *file)
{
    header_t *new_header = header_new();
    bool filled = false;
    char **lines = str_to_word_array(input_champion, "\n");

    while (!filled) {

    }
    return new_header;
}
