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
#include "my/includes/my.h"
#include "parsing/utils.h"
#include "common/includes/utils/malloc2.h"

void free_str_tab(char **tab)
{
    int index = 0;

    while (tab[index] != NULL) {
        free(tab[index]);
    }
    free(tab);
}

char *strconcat(char *dest, char *src)
{
    int len_dest = my_strlen(dest);
    int len_src = my_strlen(src);
    char *new = malloc2(sizeof(char) * (len_dest + len_src + 1));
    int index = 0;

    if (!new)
        return NULL;
    while (dest[index] != '\0') {
        new[index] = dest[index];
        index++;
    }
    for (int index_src = 0; src[index_src] != '\0'; index_src++) {
        new[index] = src[index_src];
        index++;
    }
    new[len_dest + len_src] = '\0';
    free(dest);
    return new;
}

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
    if (test_if_comment == NULL || input_separate[1] != NULL) {
        return false;
    } else {
        return true;
    }
}

bool parsing_is_empty(char *input_user)
{
    char **input_separate = str_to_word_array(input_user, " \t");

    if (input_separate[0] == NULL)
        return true;
    else
        return false;
}
