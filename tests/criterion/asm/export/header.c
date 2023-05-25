/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** Tests of assembler file exportation
*/

#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <criterion/criterion.h>
#include "export/defs.h"
#include "export/export.h"
#include "common/includes/header/header.h"

static unsigned int read_int_as_big_endian(int fd)
{
    unsigned int nb = 0;
    unsigned char buffer = 0;

    for (int i = 0; i < 4; i++) {
        read(fd, &buffer, sizeof(char));
        nb = nb << 8;
        nb |= buffer;
    }
    return nb;
}

Test(asm_export_champion_header_tests, basic)
{
    int file[2];
    header_t *header = header_new();
    char name[HEADER_NAME_SIZE + 1] = {0};
    char comment[HEADER_COMMENT_SIZE + 1] = {0};

    strcpy(header->name, "Bill");
    strcpy(header->comment, "1Equilibre");
    header->body_size = 67;
    pipe(file);
    asm_export_champion_header(header, file[1]);
    close(file[1]);
    cr_assert(read_int_as_big_endian(file[0]) == HEADER_MAGIC_CODE);
    read(file[0], name, HEADER_NAME_SIZE);
    cr_assert_str_eq(name, "Bill");
    cr_assert(read_int_as_big_endian(file[0]) == HEADER_PADDING);
    cr_assert(read_int_as_big_endian(file[0]) == header->body_size);
    read(file[0], comment, HEADER_COMMENT_SIZE);
    cr_assert_str_eq(comment, "1Equilibre");
    cr_assert(read_int_as_big_endian(file[0]) == HEADER_PADDING);
    close(file[0]);
    header_free(header);
}
