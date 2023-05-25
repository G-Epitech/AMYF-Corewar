/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** header
*/

#include <stdbool.h>
#include "parsing/parsing.h"
#include "common/includes/header/header.h"

static bool check_id(int fd)
{
    int nb = parsing_read_int(fd);

    return nb == HEADER_MAGIC_CODE;
}

header_t *parsing_header(int fd)
{
    header_t *header = NULL;

    if (!check_id(fd))
        return NULL;
    header = header_new();
    for (int i = 0; i < HEADER_NAME_SIZE; i++)
        header->name[i] = parsing_read_char(fd);
    if (parsing_read_int(fd) != 0)
        return NULL;
    header->body_size = parsing_read_int(fd);
    for (int i = 0; i < HEADER_COMMENT_SIZE; i++)
        header->comment[i] = parsing_read_char(fd);
    if (parsing_read_int(fd) != 0)
        return NULL;
    return header;
}
