/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** Corewar / Assembler / Export / Header: Export header of champion
*/

#include <unistd.h>
#include <stdbool.h>
#include "utils/utils.h"
#include "common/includes/header/defs.h"

void asm_export_champion_header_magic_code(int file)
{
    int code = HEADER_MAGIC_CODE;

    write_big_endian(file, &code, sizeof(code));
}

bool asm_export_champion_header(header_t *header, int file)
{
    (void) header;
    asm_export_champion_header_magic_code(file);
    return true;
}
