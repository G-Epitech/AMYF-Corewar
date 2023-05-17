/*
** EPITECH PROJECT, 2023
** Coreware
** File description:
** Corewar / Assembler / Export: Export a champion to specified output file
*/

#include <unistd.h>
#include "export/defs.h"
#include "export/export.h"

bool asm_export_champion(char *filename, champion_t *champion)
{
    int file = ASM_EXPORT_NULL_FD;

    if (!champion || !filename)
        return false;
    file = asm_export_create_file(filename);
    if (file == ASM_EXPORT_NULL_FD)
        return false;
    close(file);
    return true;
}
