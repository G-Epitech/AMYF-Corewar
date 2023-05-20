/*
** EPITECH PROJECT, 2022
** my_str_isnum
** File description:
** task13
*/

#include "includes/my.h"

int my_str_isnum(char const *str)
{
    int len_str_v = my_strlen(str);
    int nb_good = 0;

    if (len_str_v == 0)
        return 1;
    for (int index = 0; index < len_str_v; index++) {
        if ('0' <= str[index] && str[index] <= '9')
            nb_good++;
    }
    if (nb_good == len_str_v)
        return 1;
    else
        return 0;
}
