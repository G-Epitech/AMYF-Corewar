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
    success &= asm_export_champion_body(champion->body, file);
    return success;
}

bool asm_export_champion(char *src_file, champion_t *champion)
{
    int file = ASM_EXPORT_NULL_FD;
    bool success = true;
    char *filename = NULL;

    if (!champion || !src_file)
        return false;
    filename = asm_export_get_file_name(src_file);
    if (!filename)
        return false;
    if (!asm_export_prepare(champion->header, champion->body))
        return false;
    file = asm_export_create_file(filename);
    if (file == ASM_EXPORT_NULL_FD)
        return false;
    success &= asm_export_champion_launch(champion, file);
    free(filename);
    close(file);
    return success;
}
