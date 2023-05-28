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

#include <sys/types.h>

int my_put_nbr (int nb);
void my_putchar (char c);
int my_putstr (char const *str);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strdup (char const *src);
int my_put_error(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
char **str_to_word_array(char const *str, char *separate);
char *strconcat(char *dest, char *src);
void free_str_tab(char **tab);
void *my_memset(void *pointer, unsigned char value, size_t count);
int my_getnbr(char const *str);
int my_str_isnum(char const *str);
int my_printf(const char *format, ...);
ssize_t my_write_big_endian(int fd, const void *buff, size_t nbytes);
char *my_revstr(char  *src);
int my_putnbr_base(unsigned int nbr, char const *base);
int my_putnbr_base_len(unsigned int nbr, char const *base);
char *my_inttostr(int number);
