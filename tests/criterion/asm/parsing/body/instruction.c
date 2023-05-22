/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** Test parsing body asm champion
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

Test(cmd_handler, bad_malloc_create_cmd_struct)
{
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_FAIL);
    cr_assert_null(cmd_handler_new());
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_NORMAL);
}

Test(cmd_handler, cmd_no_exist_after_label)
{
    int argc = 2;
    char *argv[2] = {"./asm", "../tests/utils/champions/src/bad_body/no_cmd_after_label.s"};

    cr_assert_null(asm_parsing_champion(argc, argv));
}

Test(cmd_handler, cmd_no_exist_after_label_second_line)
{
    int argc = 2;
    char *argv[2] = {"./asm", "../tests/utils/champions/src/bad_body/no_cmd_label_second_line.s"};

    cr_assert_null(asm_parsing_champion(argc, argv));
}
