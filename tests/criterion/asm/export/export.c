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

    cr_assert(asm_export_champion("champion2.cor", champion));
    file = open("champion2.cor", O_WRONLY);
    cr_assert(file != ASM_EXPORT_NULL_FD);
    if (file != ASM_EXPORT_NULL_FD)
        close(file);
    champion_free(champion);
}

Test(asm_export_tests, with_null_filename)
{
    champion_t *champion = champion_new();

    cr_assert_not(asm_export_champion(NULL, champion));
    champion_free(champion);
}

Test(asm_export_tests, with_null_champion)
{
    cr_assert_not(asm_export_champion("champion3.cor", NULL));
}

Test(asm_export_tests, with_open_fail)
{
    struct rlimit save;
    struct rlimit limit;
    champion_t *champion = champion_new();

    getrlimit(RLIMIT_NOFILE, &limit);
    getrlimit(RLIMIT_NOFILE, &save);
    limit.rlim_cur = 1;
    setrlimit(RLIMIT_NOFILE, &limit);
    cr_assert_not(asm_export_champion("champion5.cor", champion));
    setrlimit(RLIMIT_NOFILE, &save);
    champion_free(champion);
}