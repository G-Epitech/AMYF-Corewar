/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** my_inttostr
*/

#include <stdlib.h>
#include <stdbool.h>
#include "includes/my.h"

static char *fill_str(int number, int length, bool neg)
{
    char *str = malloc(sizeof(char) * (length + 1));

    if (!str)
        return NULL;
    my_memset(str, '\0', length + 1);
    if (neg)
        str[0] = '-';
    while (length > neg) {
        str[--length] = '0' + (number % 10);
        number /= 10;
    }
    return str;
}

char *my_inttostr(int number)
{
    int length = 0;
    bool neg = false;
    int temp = number;

    if (temp < 0) {
        length += 1;
        neg = true;
        temp *= -1;
        number *= -1;
    }
    if (temp == 0) {
        length = 1;
    } else {
        while (temp != 0) {
            temp /= 10;
            length += 1;
        }
    }
    return fill_str(number, length, neg);
}
