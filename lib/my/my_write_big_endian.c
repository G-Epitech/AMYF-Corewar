/*
** EPITECH PROJECT, 2023
** my
** File description:
** big_endian
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

ssize_t my_write_big_endian(int fd, const void *buff, size_t nbytes)
{
    ssize_t wrote = 0;

    for (size_t i = nbytes; i > 0; i--)
        wrote += write(fd, buff + i - 1, 1);
    return wrote;
}
