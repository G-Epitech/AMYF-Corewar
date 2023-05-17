/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** Day 09, task02
** Header file that contains the prototypes of all
** the functions exposed in lib/my/libmy.a.
** Start in lib/my/ the script build.sh to build/update the library.
*/

#pragma once

int my_put_nbr (int nb);
void my_putchar (char c);
int my_putstr (char const *str);
char *my_strcpy(char *dest, char const *src);
char *my_strdup (char const *src);
int error(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);