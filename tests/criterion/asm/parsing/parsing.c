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

    cr_assert_null(!asm_parsing_champion(argc, argv));
}

Test(parsing_of_champion, bad_number_arguments)
{
    int argc = 3;
    char *argv[3] = {"./asm", "../tests/utils/champions/src/pdf.s", "test"};

    cr_assert_null(asm_parsing_champion(argc, argv));
}

Test(parsing_of_champion, bad_malloc)
{
    int argc = 2;
    char *argv[2] = {"./asm", "../tests/utils/champions/src/pdf.s"};

    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_FAIL);
    cr_assert_null(asm_parsing_champion(argc, argv));
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_NORMAL);
}

Test(parsing_of_champion, file_no_exist)
{
    int argc = 2;
    char *argv[2] = {"./asm", "../tests/utils/champions/src/no_exist.s"};

    cr_assert_null(asm_parsing_champion(argc, argv));
}

Test(parsing_of_champion, bad_file_with_nothing)
{
    int argc = 2;
    char *argv[2] = {"./asm", "../tests/utils/champions/src/bad.s"};

    cr_assert_null(asm_parsing_champion(argc, argv));
}

Test(parsing_of_champion, parsing_pdd_file)
{
    int argc = 2;
    char *argv[2] = {"./asm", "../tests/utils/champions/src/abel.s"};

    champion_t *champion = asm_parsing_champion(argc, argv);

    cr_assert_not_null(champion);
    cr_assert_str_eq(champion->header->name, "Abel");
    cr_assert_str_eq(champion->header->comment, "L'amer noir.");


    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->data, cmd_t *)->index_cmd, 10);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->data, cmd_t *)->label, NULL);

    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->data, cmd_t *)->parameters[0].type, T_REG);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->data, cmd_t *)->parameters[0].value, 1);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->data, cmd_t *)->parameters[1].type, T_DIR | T_LAB);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->data, cmd_t *)->parameters[1].value, 1);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->data, cmd_t *)->parameters[2].type, T_DIR);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->data, cmd_t *)->parameters[2].value, 1);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->data, cmd_t *)->parameters[3].type, T_NULL);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->data, cmd_t *)->parameters[3].value, 0);

    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->data, cmd_t *)->index_cmd, 0);
    cr_assert_str_eq(NODE_DATA_TO_PTR(champion->body->first->next->data, cmd_t *)->label, "hi");

    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->data, cmd_t *)->parameters[0].type, T_DIR);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->data, cmd_t *)->parameters[0].value, 234);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->data, cmd_t *)->parameters[1].type, T_NULL);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->data, cmd_t *)->parameters[1].value, 0);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->data, cmd_t *)->parameters[2].type, T_NULL);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->data, cmd_t *)->parameters[2].value, 0);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->data, cmd_t *)->parameters[3].type, T_NULL);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->data, cmd_t *)->parameters[3].value, 0);

    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->data, cmd_t *)->index_cmd, 1);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->data, cmd_t *)->label, NULL);

    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->data, cmd_t *)->parameters[0].type, T_DIR);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->data, cmd_t *)->parameters[0].value, 0);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->data, cmd_t *)->parameters[1].type, T_REG);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->data, cmd_t *)->parameters[1].value, 3);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->data, cmd_t *)->parameters[2].type, T_NULL);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->data, cmd_t *)->parameters[2].value, 0);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->data, cmd_t *)->parameters[3].type, T_NULL);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->data, cmd_t *)->parameters[3].value, 0);

    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->data, cmd_t *)->index_cmd, 8);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->data, cmd_t *)->label, NULL);

    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->data, cmd_t *)->parameters[0].type, T_DIR | T_LAB);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->data, cmd_t *)->parameters[0].value, 1);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->data, cmd_t *)->parameters[1].type, T_NULL);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->data, cmd_t *)->parameters[1].value, 0);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->data, cmd_t *)->parameters[2].type, T_NULL);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->data, cmd_t *)->parameters[2].value, 0);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->data, cmd_t *)->parameters[3].type, T_NULL);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->data, cmd_t *)->parameters[3].value, 0);
}

Test(parsing_of_champion, parsing_abel_file)
{
    int argc = 2;
    char *argv[2] = {"./asm", "../tests/utils/champions/src/pdd.s"};

    champion_t *champion = asm_parsing_champion(argc, argv);

    cr_assert_not_null(champion);
    cr_assert_str_eq(champion->header->name, "pdd");
    cr_assert_str_eq(champion->header->comment, "pdd");


    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->data, cmd_t *)->index_cmd, 10);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->data, cmd_t *)->label, NULL);

    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->data, cmd_t *)->parameters[0].type, T_REG);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->data, cmd_t *)->parameters[0].value, 1);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->data, cmd_t *)->parameters[1].type, T_DIR | T_LAB);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->data, cmd_t *)->parameters[1].value, 9);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->data, cmd_t *)->parameters[2].type, T_DIR);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->data, cmd_t *)->parameters[2].value, 1);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->data, cmd_t *)->parameters[3].type, T_NULL);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->data, cmd_t *)->parameters[3].value, 0);

    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->data, cmd_t *)->index_cmd, 11);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->data, cmd_t *)->label, NULL);

    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->data, cmd_t *)->parameters[0].type, T_DIR | T_LAB);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->data, cmd_t *)->parameters[0].value, 9);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->data, cmd_t *)->parameters[1].type, T_NULL);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->data, cmd_t *)->parameters[1].value, 0);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->data, cmd_t *)->parameters[2].type, T_NULL);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->data, cmd_t *)->parameters[2].value, 0);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->data, cmd_t *)->parameters[3].type, T_NULL);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->data, cmd_t *)->parameters[3].value, 0);

    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->data, cmd_t *)->index_cmd, 1);
    cr_assert_str_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->data, cmd_t *)->label, "begin");

    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->data, cmd_t *)->parameters[0].type, T_DIR);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->data, cmd_t *)->parameters[0].value, 76);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->data, cmd_t *)->parameters[1].type, T_REG);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->data, cmd_t *)->parameters[1].value, 1);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->data, cmd_t *)->parameters[2].type, T_NULL);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->data, cmd_t *)->parameters[2].value, 0);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->data, cmd_t *)->parameters[3].type, T_NULL);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->data, cmd_t *)->parameters[3].value, 0);

    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->data, cmd_t *)->index_cmd, 1);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->data, cmd_t *)->label, NULL);

    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->data, cmd_t *)->parameters[0].type, T_DIR);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->data, cmd_t *)->parameters[0].value, 40);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->data, cmd_t *)->parameters[1].type, T_REG);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->data, cmd_t *)->parameters[1].value, 6);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->data, cmd_t *)->parameters[2].type, T_NULL);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->data, cmd_t *)->parameters[2].value, 0);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->data, cmd_t *)->parameters[3].type, T_NULL);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->data, cmd_t *)->parameters[3].value, 0);

    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->data, cmd_t *)->index_cmd, 1);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->data, cmd_t *)->label, NULL);

    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->data, cmd_t *)->parameters[0].type, T_DIR);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->data, cmd_t *)->parameters[0].value, 1);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->data, cmd_t *)->parameters[1].type, T_REG);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->data, cmd_t *)->parameters[1].value, 7);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->data, cmd_t *)->parameters[2].type, T_NULL);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->data, cmd_t *)->parameters[2].value, 0);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->data, cmd_t *)->parameters[3].type, T_NULL);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->data, cmd_t *)->parameters[3].value, 0);

    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->next->data, cmd_t *)->index_cmd, 1);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->next->data, cmd_t *)->label, NULL);

    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->next->data, cmd_t *)->parameters[0].type, T_DIR);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->next->data, cmd_t *)->parameters[0].value, 15);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->next->data, cmd_t *)->parameters[1].type, T_REG);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->next->data, cmd_t *)->parameters[1].value, 4);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->next->data, cmd_t *)->parameters[2].type, T_NULL);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->next->data, cmd_t *)->parameters[2].value, 0);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->next->data, cmd_t *)->parameters[3].type, T_NULL);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->next->data, cmd_t *)->parameters[3].value, 0);

    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->next->next->data, cmd_t *)->index_cmd, 1);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->next->next->data, cmd_t *)->label, NULL);

    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->next->next->data, cmd_t *)->parameters[0].type, T_DIR);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->next->next->data, cmd_t *)->parameters[0].value, 15);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->next->next->data, cmd_t *)->parameters[1].type, T_REG);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->next->next->data, cmd_t *)->parameters[1].value, 5);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->next->next->data, cmd_t *)->parameters[2].type, T_NULL);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->next->next->data, cmd_t *)->parameters[2].value, 0);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->next->next->data, cmd_t *)->parameters[3].type, T_NULL);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->next->next->data, cmd_t *)->parameters[3].value, 0);

    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->next->next->next->data, cmd_t *)->index_cmd, 4);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->next->next->next->data, cmd_t *)->label, NULL);

    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->next->next->next->data, cmd_t *)->parameters[0].type, T_REG);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->next->next->next->data, cmd_t *)->parameters[0].value, 4);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->next->next->next->data, cmd_t *)->parameters[1].type, T_REG);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->next->next->next->data, cmd_t *)->parameters[1].value, 5);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->next->next->next->data, cmd_t *)->parameters[2].type, T_REG);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->next->next->next->data, cmd_t *)->parameters[2].value, 3);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->next->next->next->data, cmd_t *)->parameters[3].type, T_NULL);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->next->next->next->data, cmd_t *)->parameters[3].value, 0);

    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->next->next->next->next->data, cmd_t *)->index_cmd, 8);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->next->next->next->next->data, cmd_t *)->label, NULL);

    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->next->next->next->next->data, cmd_t *)->parameters[0].type, T_DIR | T_LAB);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->next->next->next->next->data, cmd_t *)->parameters[0].value, 12);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->next->next->next->next->data, cmd_t *)->parameters[1].type, T_NULL);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->next->next->next->next->data, cmd_t *)->parameters[1].value, 0);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->next->next->next->next->data, cmd_t *)->parameters[2].type, T_NULL);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->next->next->next->next->data, cmd_t *)->parameters[2].value, 0);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->next->next->next->next->data, cmd_t *)->parameters[3].type, T_NULL);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->next->next->next->next->data, cmd_t *)->parameters[3].value, 0);

    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->next->next->next->next->next->data, cmd_t *)->index_cmd, 0);
    cr_assert_str_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->next->next->next->next->next->data, cmd_t *)->label, "live");

    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->next->next->next->next->next->data, cmd_t *)->parameters[0].type, T_DIR);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->next->next->next->next->next->data, cmd_t *)->parameters[0].value, 2);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->next->next->next->next->next->data, cmd_t *)->parameters[1].type, T_NULL);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->next->next->next->next->next->data, cmd_t *)->parameters[1].value, 0);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->next->next->next->next->next->data, cmd_t *)->parameters[2].type, T_NULL);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->next->next->next->next->next->data, cmd_t *)->parameters[2].value, 0);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->next->next->next->next->next->data, cmd_t *)->parameters[3].type, T_NULL);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->next->next->next->next->next->data, cmd_t *)->parameters[3].value, 0);

    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->next->next->next->next->next->next->data, cmd_t *)->index_cmd, 1);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->next->next->next->next->next->next->data, cmd_t *)->label, NULL);

    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->next->next->next->next->next->next->data, cmd_t *)->parameters[0].type, T_DIR);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->next->next->next->next->next->next->data, cmd_t *)->parameters[0].value, 0);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->next->next->next->next->next->next->data, cmd_t *)->parameters[1].type, T_REG);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->next->next->next->next->next->next->data, cmd_t *)->parameters[1].value, 4);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->next->next->next->next->next->next->data, cmd_t *)->parameters[2].type, T_NULL);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->next->next->next->next->next->next->data, cmd_t *)->parameters[2].value, 0);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->next->next->next->next->next->next->data, cmd_t *)->parameters[3].type, T_NULL);
    cr_assert_eq(NODE_DATA_TO_PTR(champion->body->first->next->next->next->next->next->next->next->next->next->next->data, cmd_t *)->parameters[3].value, 0);
}
