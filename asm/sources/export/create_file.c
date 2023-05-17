/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** Corewar / Assembler / Export: Create file for champion exportation
*/

#include <fcntl.h>
#include "export/defs.h"

int asm_export_create_file(char *filename)
{
    int file = ASM_EXPORT_NULL_FD;

    if (filename) {
        file = open(filename, O_TRUNC | O_CREAT | O_WRONLY,
        ASM_EXPORT_FILE_PERMS);
    }
    return file;
}
