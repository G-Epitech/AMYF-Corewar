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

Test(create_label, bad_cmd)
{
    int argc = 2;
    char *argv[2] = {"./asm", "../tests/utils/champions/src/bad_body/bad_cmd.s"};

    cr_assert_null(asm_parsing_champion(argc, argv));
}

Test(create_label, file_wh_comment)
{
    int argc = 2;
    char *argv[2] = {"./asm", "../tests/utils/champions/src/bad_body/comment.s"};

    cr_assert_not_null(asm_parsing_champion(argc, argv));
}

Test(create_label, cmd_too_many_args)
{
    int argc = 2;
    char *argv[2] = {"./asm", "../tests/utils/champions/src/bad_body/too_many_args.s"};

    cr_assert_null(asm_parsing_champion(argc, argv));
}

Test(cmd_handler, bad_malloc_parsing_body)
{
    champion_t *test = champion_new();

    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_FAIL);
    cr_assert_null(parsing_champion_body(NULL, test));
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_NORMAL);
}
