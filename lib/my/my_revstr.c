/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** my_revstr
*/

#include "includes/my.h"

char *my_revstr(char *src)
{
    int j = my_strlen(src) - 1;
    char temp = '\0';

    for (int i = 0; i < j ; i++) {
        temp = src[i];
        src[i] = src[j];
        src[j] = temp;
        j--;
    }
    return src;
}
