/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** Tests of assembler file exportation
*/

#include <fcntl.h>
#include <unistd.h>
#include <criterion/criterion.h>
#include "export/defs.h"
#include "export/export.h"
#include "common/includes/champion/champion.h"

Test(asm_export_tests, basic)
{
    int file = ASM_EXPORT_NULL_FD;
    champion_t *champion = champion_new();

    cr_assert(asm_export_champion("champion2.core", champion));
    file = open("champion2.core", O_WRONLY);
    cr_assert(file != ASM_EXPORT_NULL_FD);
    if (file != ASM_EXPORT_NULL_FD) {
        
    }
}

Test(asm_export_create_file_tests, with_null_file_name)
{
    cr_assert(asm_export_create_file(NULL) == ASM_EXPORT_NULL_FD);
}
