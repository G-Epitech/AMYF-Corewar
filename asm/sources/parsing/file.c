/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** asm parsing
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "my/include/my.h"
#include "parsing/utils.h"
#include "parsing/parsing.h"
#include "common/include/utils/malloc2.h"

file_t *new_file(char *input_file)
{
    file_t *new_file = malloc2(sizeof(file_t));

    if (!new_file)
        return NULL;
    new_file->index_line = 0;
    new_file->lines = str_to_word_array(input_file, "\n");
    return new_file;
}

char *parse_file(char *file_path)
{
    FILE *fp = fopen(file_path, "r");
    char *input_champion = malloc2(sizeof(char) * 1);;
    char *line_input_champion = NULL;
    size_t input_len = 0;

    input_champion[0] = '\0';
    while (getline(&line_input_champion, &input_len, fp) != -1) {
        input_champion = strconcat(input_champion, line_input_champion);
    }
    return input_champion;
}
