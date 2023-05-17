/*
** EPITECH PROJECT, 2022
** my_strconcat.c
** File description:
** concat two str
*/

#include <stdlib.h>
#include "includes/my.h"

char *strconcat(char *dest, char *src)
{
    int len_dest = my_strlen(dest);
    int len_src = my_strlen(src);
    char *new = malloc(sizeof(char) * (len_dest + len_src + 1));
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
