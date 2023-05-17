/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** Corewar / Assembler / Utils / Write / Big Endian: write bytes as big endian
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

ssize_t write_big_endian(int fd, const void *buff, size_t nbytes)
{
    ssize_t wrote = 0;

    for (size_t i = nbytes; i > 0; i--)
        wrote += write(fd, &(buff[i - 1]), 1);
    return wrote;
}
