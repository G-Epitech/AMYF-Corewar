/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** read
*/

#include <unistd.h>
#include <stdlib.h>

unsigned int parsing_read_int(int fd)
{
    unsigned int nb = 0;
    unsigned char buffer = 0;
    int readed = 0;

    for (int i = 0; i < 4; i++) {
        readed = read(fd, &buffer, sizeof(char));
        if (readed == -1) {
            write(2, "Incorrect Body Size.\n", 21);
            exit(84);
        }
        nb = nb << 8;
        nb |= buffer;
    }
    return nb;
}

unsigned short parsing_read_short(int fd)
{
    unsigned short nb = 0;
    unsigned char buffer = 0;
    int readed = 0;

    for (int i = 0; i < 2; i++) {
        readed = read(fd, &buffer, sizeof(char));
        if (readed == -1) {
            write(2, "Incorrect Body Size.\n", 21);
            exit(84);
        }
        nb = nb << 8;
        nb |= buffer;
    }
    return nb;
}

unsigned char parsing_read_char(int fd)
{
    unsigned char buffer = 0;
    int readed = 0;

    readed = read(fd, &buffer, sizeof(char));
    if (readed == -1) {
        write(2, "Incorrect Body Size.\n", 21);
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
            write(2, "Incorrect Body Size.\n", 21);
            exit(84);
        }
        nb = nb << 8;
        nb |= buffer;
    }
    return nb;
}
