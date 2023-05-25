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
#include "parsing/utils.h"
#include "my/includes/my.h"
#include "parsing/parsing.h"
#include "common/includes/cmd/cmd.h"
#include "common/includes/list/list.h"
#include "common/includes/utils/malloc2.h"
#include "common/includes/header/header.h"
#include "common/includes/champion/champion.h"

Test(create_label, bad_malloc_label)
{
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_FAIL);
    cr_assert_null(label_new());
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_NORMAL);
}

Test(create_label, bad_list_argument)
{
    label_t *new = label_new();

    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_FAIL);
    cr_assert_not(label_append(NULL, new));
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_NORMAL);
}

Test(create_label, bad_label_argument)
{
    list_t *new = list_new();

    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_FAIL);
    cr_assert_not(label_append(new, NULL));
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_NORMAL);
}

Test(create_label, bad_malloc)
{
    list_t *new_list = list_new();
    label_t *new_label = label_new();

    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_FAIL);
    cr_assert_not(label_append(new_list, new_label));
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_NORMAL);
}

Test(create_label, bad_malloc_label_handler)
{
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_FAIL);
    cr_assert_null(label_handler_new());
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_NORMAL);
}

Test(create_label, label_already_exist)
{
    int argc = 2;
    char *argv[2] = {"./asm", "../tests/utils/champions/src/bad_body/label_already_exist.s"};

    cr_assert_null(asm_parsing_champion(argc, argv));
}

Test(create_label, label_already_exist_differente_line)
{
    int argc = 2;
    char *argv[2] = {"./asm", "../tests/utils/champions/src/bad_body/label_already_exist_diffrentes_lines.s"};

    cr_assert_null(asm_parsing_champion(argc, argv));
}

Test(create_label, bad_malloc_label_find)
{
    label_handler_t *label_handler = label_handler_new();
    file_t *file = file_new("../tests/utils/champions/src/abel.s");

    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_FAIL);
    cr_assert_not(label_find(label_handler, file));
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_NORMAL);
}
