/*
** EPITECH PROJECT, 2022
** my_getnbr
** File description:
** tool
*/

#include <stdbool.h>
#include "includes/my.h"

static bool handle_digit(char digit, long *nbr, short *sign, bool *find_state)
{
    if ((!(*find_state) && digit != '0') || *find_state) {
        *nbr = *nbr * 10 + (digit - '0');
        if ((*sign > 0 && *nbr > 2147483647)
            || (*sign < 0 && -(*nbr) < -2147483648)) {
            *nbr = 0;
            return false;
        }
    }
    return true;
}

static void handle_sign(char s, short *sign)
{
    if (s == '-')
        *sign = *sign * -1;
}

static bool check_continue(short *sign, bool find_state)
{
    if (!find_state)
        *sign = 1;
    return !find_state;
}

static bool handle_char(char c, short *sign, long *nbr, bool *find_state)
{
    bool r = true;

    if ((c == '-' || c == '+') && !(*find_state)) {
        handle_sign(c, sign);
    } else if (c >= '0' && c <= '9') {
        r = handle_digit(c, nbr, sign, find_state);
        *find_state = true;
    } else {
        r = check_continue(sign, *find_state);
    }
    return r;
}

int my_getnbr(char const *str)
{
    short sign = 1;
    bool find_state = 0;
    int len = my_strlen(str);
    long nbr = 0;

    for (int i = 0; i < len; i++)
        i = handle_char(str[i], &sign, &nbr, &find_state) ? i : len;
    return sign * nbr;
}
