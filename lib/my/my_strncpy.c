/*
** EPITECH PROJECT, 2022
** my_strncpy
** File description:
** tool
*/
#include "includes/my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int len = my_strlen(dest);

    while (src[i] != '\0' && i < n) {
        dest[i] = src[i];
        i++;
    }
    if (i < n) dest[i] = '\0';
    return (dest);
}
