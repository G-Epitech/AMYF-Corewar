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
#include "my/include/my.h"
#include "parsing/utils.h"
#include "common/include/utils/malloc2.h"

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

char *filter_comment(char *input_user)
{
    char **input_separate = NULL;

    if (my_strcmp("##start\n", input_user) == 0 ||
    my_strcmp("##end\n", input_user) == 0) {
        return input_user;
    } else {
        input_separate = str_to_word_array(input_user, "#");
        return input_separate[0];
    }
    return NULL;
}

bool is_comment(char *input_user)
{
    char *test_if_comment = NULL;
    char **input_separate = str_to_word_array(input_user, "#");

    test_if_comment = my_strstr(input_user, "#");
    if (test_if_comment == NULL || input_separate[1] != NULL) {
        return false;
    } else if (my_strcmp(test_if_comment, "##start\n") == 0 ||
    my_strcmp(test_if_comment, "##end\n") == 0) {
        return false;
    } else {
        return true;
    }
}
