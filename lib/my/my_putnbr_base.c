/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** my_putnbr_base
*/

#include "includes/my.h"

int my_putnbr_base_len(unsigned int nbr, char const *base)
{
    int len = my_strlen(base);
    int index = 0;
    int temp = 0;
    char result[32000];

    my_memset(result, '\0', sizeof(char) * 32000);
    while (nbr != 0) {
        result[index] = base[nbr % len];
        nbr = nbr / len;
        index++;
    }
    return (index + 1);
}

int my_putnbr_base(unsigned int nbr, char const *base)
{
    int len = my_strlen(base);
    int index = 0;
    int temp = 0;
    char result[32000];

    my_memset(result, '\0', sizeof(char) * 32000);
    while (nbr != 0) {
        result[index] = base[nbr % len];
        nbr = nbr / len;
        index++;
    }
    my_revstr(result);
    if (index != 0)
        my_putstr(result);
    else
        my_putchar('0');
    return (index + 1);
}
