/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** Tests of assembler file exportation
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>
#include <criterion/criterion.h>
#include "export/defs.h"
#include "export/export.h"

Test(asm_export_create_file_tests, basic)
{
    int file = asm_export_create_file("champion1.cor");

    cr_assert(file != ASM_EXPORT_NULL_FD);
    if (file != ASM_EXPORT_NULL_FD) {
        close(file);
        remove("champion1.cor");
    }
}

Test(asm_export_create_file_tests, with_null_file_name)
{
    cr_assert(asm_export_create_file(NULL) == ASM_EXPORT_NULL_FD);
}

Test(asm_export_create_file_tests, with_open_fail)
{
    struct rlimit save;
    struct rlimit limit;

    getrlimit(RLIMIT_NOFILE, &limit);
    getrlimit(RLIMIT_NOFILE, &save);
    limit.rlim_cur = 1;
    setrlimit(RLIMIT_NOFILE, &limit);
    cr_assert(asm_export_create_file("champion4.cor") == ASM_EXPORT_NULL_FD);
    setrlimit(RLIMIT_NOFILE, &save);
}
