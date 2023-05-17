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
    unsigned int nb = parsing_read_int(fd);

    return nb == HEADER_MAGIC_CODE;
}

bool parsing_header(champion_t *champion, int fd)
{
    if (!check_id(fd))
        return false;
    champion->header = header_new();
    for (int i = 0; i < HEADER_NAME_SIZE; i++)
        champion->header->name[i] = parsing_read_char(fd);
    champion->header->body_size = parsing_read_long_int(fd);
    for (int i = 0; i < HEADER_COMMENT_SIZE; i++)
        champion->header->comment[i] = parsing_read_char(fd);
    return true;
}
