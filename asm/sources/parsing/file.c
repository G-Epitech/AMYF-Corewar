/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** asm parsing
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "my/includes/my.h"
#include "parsing/utils.h"
#include "parsing/parsing.h"
#include "common/includes/utils/malloc2.h"

file_t *file_new(char *input_file)
{
    file_t *file_new = malloc2(sizeof(file_t));

    if (!file_new)
        return NULL;
    file_new->index_line = 0;
    file_new->lines = str_to_word_array(input_file, "\n");
    return file_new;
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