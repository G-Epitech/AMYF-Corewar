/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** Tests of assembler file exportation
*/

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>
#include <criterion/criterion.h>
#include "parsing/parsing.h"
#include "common/includes/cmd/cmd.h"
#include "common/includes/utils/malloc2.h"
#include "common/includes/header/header.h"
#include "common/includes/champion/champion.h"

Test(parsing_of_champion, simple_execution)
{
    int argc = 2;
    char *argv[2] = {"./asm", "../tests/utils/champions/src/pdf.s"};

    cr_assert_null(parse_champion(argc, argv));
}

Test(parsing_of_champion, bad_number_arguments)
{
    int argc = 3;
    char *argv[3] = {"./asm", "../tests/utils/champions/src/pdf.s", "test"};

    cr_assert_null(parse_champion(argc, argv));
}

Test(parsing_of_champion, bad_malloc)
{
    int argc = 2;
    char *argv[2] = {"./asm", "../tests/utils/champions/src/pdf.s"};

    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_FAIL);
    cr_assert_null(parse_champion(argc, argv));
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_NORMAL);
}

Test(parsing_of_champion, file_no_exist)
{
    int argc = 2;
    char *argv[2] = {"./asm", "../tests/utils/champions/src/no_exist.s"};

    cr_assert_null(parse_champion(argc, argv));
}

Test(parsing_of_champion, bad_file_with_nothing)
{
    int argc = 2;
    char *argv[2] = {"./asm", "../tests/utils/champions/src/bad.s"};

    cr_assert_null(parse_champion(argc, argv));
}
