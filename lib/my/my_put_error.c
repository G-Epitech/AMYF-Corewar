/*
** EPITECH PROJECT, 2022
** error
** File description:
** @Made by Math alias T1nt1n
** Error file
*/

#include <unistd.h>
#include "includes/my.h"

int my_put_error(char *str)
{
    write(2, str, my_strlen(str));
    return 0;
}
