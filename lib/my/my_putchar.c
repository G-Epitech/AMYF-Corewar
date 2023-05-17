/*
** EPITECH PROJECT, 2022
** tests_my_putchar.c
** File description:
** char file
*/

#include <unistd.h>
#include "includes/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
