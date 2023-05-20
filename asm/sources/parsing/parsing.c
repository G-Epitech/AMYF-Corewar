/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** asm parsing
*/

#include "parsing/utils.h"
#include "my/includes/my.h"
#include "parsing/parsing.h"
#include "common/includes/cmd/cmd.h"
#include "common/includes/header/header.h"
#include "common/includes/champion/champion.h"

static void remove_bad_line(file_t *file)
{
    while (file->lines[file->index_line] != NULL) {
        if (!parsing_wrong_line(file))
            return;
        file->index_line++;
    }
}

champion_t *parsing_champion(int argc, char **argv)
{
    champion_t *champion = NULL;
    file_t *file = NULL;
    char *input_champion = NULL;

    if (argc != 2)
        return NULL;
    champion = champion_new();
    input_champion = parsing_parse_file(argv[1]);
    if (!champion || !input_champion)
        return NULL;
    file = file_new(input_champion);
    champion->header = parsing_champion_header(file);
    if (champion->header == NULL)
        return NULL;
    remove_bad_line(file);
    if (!parsing_champion_body(file, champion))
        return NULL;
    file_free(file);
    return champion;
}
