/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** Tests of assembler file exportation
*/

#include <unistd.h>
#include <criterion/criterion.h>
#include "export/defs.h"
#include "export/export.h"

Test(asm_export_create_file_tests, basic)
{
    int file = asm_export_create_file("champion1.core");

    cr_assert(file != ASM_EXPORT_NULL_FD);
    if (file != ASM_EXPORT_NULL_FD) {
        close(file);
        remove("champion1.core");
    }
}

Test(asm_export_create_file_tests, with_null_file_name)
{
    cr_assert(asm_export_create_file(NULL) == ASM_EXPORT_NULL_FD);
}
