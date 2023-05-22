/*
** EPITECH PROJECT, 2023
** Coreware
** File description:
** Corewar / Assembler / Export: Export a champion to specified output file
*/

#include <unistd.h>
#include "export/defs.h"
#include "export/export.h"

bool asm_export_champion_launch(champion_t *champion, int file)
{
    bool success = true;

    asm_export_champion_header(champion->header, file);
    return success;
}

bool asm_export_champion(char *filename, champion_t *champion)
{
    int file = ASM_EXPORT_NULL_FD;
    bool success = true;

    if (!champion || !filename)
        return false;
    if (!asm_export_prepare(champion->header, champion->body))
        return false;
    file = asm_export_create_file(filename);
    if (file == ASM_EXPORT_NULL_FD)
        return false;
    success &= asm_export_champion_launch(champion, file);
    close(file);
    return success;
}
