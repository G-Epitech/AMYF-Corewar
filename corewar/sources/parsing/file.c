/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** file
*/

#include <fcntl.h>

#include <stdio.h>

int parsing_file_open(char *file)
{
    int fd = 0;

    if (!file)
        return -1;
    fd = open(file, O_RDONLY);
    return fd;
}
