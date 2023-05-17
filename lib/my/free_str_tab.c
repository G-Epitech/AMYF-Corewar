/*
** EPITECH PROJECT, 2022
** my_strconcat.c
** File description:
** concat two str
*/

#include <stdlib.h>
#include "includes/my.h"

void free_str_tab(char **tab)
{
    int index = 0;

    while (tab[index] != NULL)
        free(tab[index]);
    free(tab);
}
