/*
** EPITECH PROJECT, 2022
** my_str_to_word_array
** File description:
** task04 day08
*/

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "includes/my.h"

bool my_char_is_in_str(char c, char* separate)
{
    for (int index = 0; separate[index] != '\0'; index++) {
        if (separate[index] == c)
            return true;
    }
    return false;
}

bool my_char_is_alpha(char c, char *separate)
{
    if (my_char_is_in_str(c, separate))
        return false;
    else
        return true;
}

int countword(char const *str, char *separate)
{
    int nb_word = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((my_char_is_alpha(str[i], separate))) {
            nb_word++;
        }
        for (; ((my_char_is_alpha(str[i], separate))) && str[i] != '\0'; i++) {
        }
        if (str[i] == '\0')
            i--;
    }
    return nb_word;
}

int count_letter_of_word(char const *str, int *index_word, char *separate)
{
    int nb_letter = 0;

    while (str[*index_word] != '\0' && !my_char_is_alpha(str[*index_word],
    separate))
        (*index_word)++;
    while (str[*index_word] != '\0' && my_char_is_alpha(str[*index_word],
    separate)) {
        nb_letter++;
        (*index_word)++;
        if (!((my_char_is_alpha(str[*index_word], separate)))) {
            return nb_letter;
        }
    }
    return nb_letter;
}

char **str_to_word_array(char const *str, char *separate)
{
    int index_word = 0;
    int nb = 0;
    char **str_tab = malloc(sizeof(char *) * (countword(str, separate) + 1));
    int count = 0;

    if (str_tab == NULL)
        return NULL;
    for (int x = 0; x < countword(str, separate); x++) {
        nb = count_letter_of_word(str, &index_word, separate);
        str_tab[x] = malloc(sizeof(char) * ((nb) + 1));
        if (str_tab[x] == NULL)
            return NULL;
        for (int index = (index_word - nb); index < index_word; index++)
            str_tab[x][count++] = str[index];
        count = 0;
        str_tab[x][nb] = '\0';
    }
    str_tab[countword(str, separate)] = NULL;
    return str_tab;
}
