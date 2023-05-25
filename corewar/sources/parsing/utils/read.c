/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** read
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my/includes/my.h"

int parsing_read_int(int fd)
{
    unsigned int nb = 0;
    unsigned char buffer = 0;
    int readed = 0;

    for (int i = 0; i < 4; i++) {
        readed = read(fd, &buffer, sizeof(char));
        if (readed == -1) {
            error("Incorrect Body Size.\n");
            exit(84);
        }
        nb = nb << 8;
        nb |= buffer;
    }
    return nb;
}

short parsing_read_short(int fd)
{
    unsigned short nb = 0;
    unsigned char buffer = 0;
    int readed = 0;

    for (int i = 0; i < 2; i++) {
        readed = read(fd, &buffer, sizeof(char));
        if (readed == -1) {
            error("Incorrect Body Size.\n");
            exit(84);
        }
        nb = nb << 8;
        nb |= buffer;
    }
    return nb;
}

char parsing_read_char(int fd)
{
    unsigned char buffer = 0;
    int readed = 0;

    readed = read(fd, &buffer, sizeof(char));
    if (readed == -1) {
        error("Incorrect Body Size.\n");
        exit(84);
    }
    return buffer;
}

unsigned long int parsing_read_long_int(int fd)
{
    unsigned long int nb = 0;
    unsigned char buffer = 0;
    int readed = 0;

    for (int i = 0; i < 8; i++) {
        readed = read(fd, &buffer, sizeof(char));
        if (readed == -1) {
            error("Incorrect Body Size.\n");
            exit(84);
        }
        nb = nb << 8;
        nb |= buffer;
    }
    return nb;
}
