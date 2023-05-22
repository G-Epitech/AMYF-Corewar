/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** asm parsing
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include "parsing/utils.h"
#include "my/includes/my.h"
#include "parsing/parsing.h"
#include "common/includes/utils/malloc2.h"
#include "common/includes/header/header.h"
#include "common/includes/champion/champion.h"

char *parsing_filter_comment(char *input_user)
{
    char **input_separate = NULL;

    input_separate = str_to_word_array(input_user, "#");
    return input_separate[0];
}

bool parsing_is_comment(char *input_user)
{
    char *test_if_comment = NULL;
    char **input_separate = str_to_word_array(input_user, "#");

    test_if_comment = my_strstr(input_user, "#");
    return !(test_if_comment == NULL || input_separate[1] != NULL);
}

bool parsing_is_empty(char *input_user)
{
    char **input_separate = str_to_word_array(input_user, " \t");

    if (input_separate[0] == NULL)
        return true;
    else
        return false;
}

bool parsing_wrong_line(file_t *file)
{
    if (parsing_is_empty(file->lines[file->index_line])) {
        file->index_line++;
        return true;
    }
    if (parsing_is_comment(file->lines[file->index_line])) {
        file->index_line++;
        return true;
    }
    return false;
}
