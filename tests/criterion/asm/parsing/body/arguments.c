/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** Tests parsing body champion asm
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

Test(create_label, too_high_register)
{
    int argc = 2;
    char *argv[2] = {"./asm", "../tests/utils/champions/src/bad_body/too_hish_registers.s"};

    cr_assert_null(asm_parsing_champion(argc, argv));
}

Test(create_label, bad_arguments)
{
    int argc = 2;
    char *argv[2] = {"./asm", "../tests/utils/champions/src/bad_body/bad_arguments.s"};

    cr_assert_null(asm_parsing_champion(argc, argv));
}

Test(create_label, bad_placement_register)
{
    int argc = 2;
    char *argv[2] = {"./asm", "../tests/utils/champions/src/bad_body/bad_placement_register.s"};

    cr_assert_null(asm_parsing_champion(argc, argv));
}

Test(test_indirect_number, test_indirect_number)
{
    int argc = 2;
    char *argv[2] = {"./asm", "../tests/utils/champions/src/bad_body/indirect_number.s"};

    cr_assert_not_null(asm_parsing_champion(argc, argv));
}

Test(test_indirect_number, bad_placement_indirect_number)
{
    int argc = 2;
    char *argv[2] = {"./asm", "../tests/utils/champions/src/bad_body/bad_placement_indirect.s"};

    cr_assert_null(asm_parsing_champion(argc, argv));
}

Test(test_indirect_number, bad_indirect_alpha)
{
    int argc = 2;
    char *argv[2] = {"./asm", "../tests/utils/champions/src/bad_body/bad_indirect_alpha.s"};

    cr_assert_null(asm_parsing_champion(argc, argv));
}

Test(test_indirect_number, two_label)
{
    int argc = 2;
    char *argv[2] = {"./asm", "../tests/utils/champions/src/bad_body/two_labels.s"};

    cr_assert_not_null(asm_parsing_champion(argc, argv));
}

Test(test_indirect_number, call_bad_label)
{
    int argc = 2;
    char *argv[2] = {"./asm", "../tests/utils/champions/src/bad_body/call_bad_label.s"};

    cr_assert_null(asm_parsing_champion(argc, argv));
}

Test(test_indirect_number, bad_placement_direct_label)
{
    int argc = 2;
    char *argv[2] = {"./asm", "../tests/utils/champions/src/bad_body/bad_placement_direct_label.s"};

    cr_assert_null(asm_parsing_champion(argc, argv));
}

Test(test_indirect_number, bad_placement_indirect_label)
{
    int argc = 2;
    char *argv[2] = {"./asm", "../tests/utils/champions/src/bad_body/bad_placement_indirect_label.s"};

    cr_assert_null(asm_parsing_champion(argc, argv));
}

Test(test_indirect_number, bad_malloc_argument)
{
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_FAIL);
    cr_assert_not(parsing_arguments(NULL, NULL, NULL, NULL));
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_NORMAL);
}
