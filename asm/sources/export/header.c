/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** Corewar / Assembler / Export / Header: Export header of champion
*/

#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include "my/includes/my.h"
#include "common/includes/header/defs.h"

void asm_export_champion_header(header_t *header, int file)
{
    int magic = HEADER_MAGIC_CODE;
    int padding = HEADER_PADDING;

    my_write_big_endian(file, &magic, sizeof(magic));
    write(file, &(header->name), HEADER_NAME_SIZE);
    write(file, &padding, HEADER_PADDING_SIZE);
    my_write_big_endian(file, &(header->body_size),
    sizeof(header->body_size));
    write(file, &(header->comment), HEADER_COMMENT_SIZE);
    write(file, &padding, HEADER_PADDING_SIZE);
}
