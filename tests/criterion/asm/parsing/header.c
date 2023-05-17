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

Test(parsing_header_of_champion, basic_pdf_file)
{
    champion_t *champion = champion_new();
    file_t *file = NULL;
    char *input_champion = parsing_parse_file("../tests/utils/champions/src/pdf.s");

    file = file_new(input_champion);
    champion->header = parsing_champion_header(file);
    cr_assert_str_eq(champion->header->name, "Jon Snow");
    cr_assert_str_eq(champion->header->comment, "Winter is coming");
    file_free(file);
}

Test(parsing_header_of_champion, basic_bill_file)
{
    champion_t *champion = champion_new();
    file_t *file = NULL;
    char *input_champion = parsing_parse_file("../tests/utils/champions/src/bill.s");

    file = file_new(input_champion);
    champion->header = parsing_champion_header(file);
    cr_assert_str_eq(champion->header->name, "Bill");
    cr_assert_str_eq(champion->header->comment, "1Equilibre");
    file_free(file);
}

Test(parsing_header_of_champion, basic_pdd_file)
{
    champion_t *champion = champion_new();
    file_t *file = NULL;
    char *input_champion = parsing_parse_file("../tests/utils/champions/src/pdd.s");

    file = file_new(input_champion);
    champion->header = parsing_champion_header(file);
    cr_assert_str_eq(champion->header->name, "pdd");
    cr_assert_str_eq(champion->header->comment, "pdd");
}

Test(parsing_header_of_champion, basic_abel_file)
{
    champion_t *champion = champion_new();
    file_t *file = NULL;
    char *input_champion = parsing_parse_file("../tests/utils/champions/src/abel.s");

    file = file_new(input_champion);
    champion->header = parsing_champion_header(file);
    cr_assert_str_eq(champion->header->name, "Abel");
    cr_assert_str_eq(champion->header->comment, "L'amer noir.");
}

Test(parsing_header_of_champion, basic_tyron_file)
{
    champion_t *champion = champion_new();
    file_t *file = NULL;
    char *input_champion = parsing_parse_file("../tests/utils/champions/src/tyron.s");

    file = file_new(input_champion);
    champion->header = parsing_champion_header(file);
    cr_assert_str_eq(champion->header->name, "Tyron");
    cr_assert_str_eq(champion->header->comment, "Just a basic pompes, traction program");
}

Test(parsing_of_champion, bad_malloc_new_file)
{
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_FAIL);
    cr_assert_null(file_new("test"));
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_NORMAL);
}

Test(parsing_of_champion, bad_malloc_parsing_parse_file)
{
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_FAIL);
    cr_assert_null(parsing_parse_file("test"));
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_NORMAL);
}

Test(parsing_of_champion, file_with_name_too_long)
{
    file_t *file = NULL;
    char *input_champion = parsing_parse_file("../tests/utils/champions/src/name_too_long.s");

    file = file_new(input_champion);
    cr_assert_null(parsing_champion_header(file));
}

Test(parsing_of_champion, file_with_comment_too_long)
{
    file_t *file = NULL;
    char *input_champion = parsing_parse_file("../tests/utils/champions/src/comment_too_long.s");

    file = file_new(input_champion);
    cr_assert_null(parsing_champion_header(file));
}

Test(parsing_of_champion, file_with_bad_word)
{
    file_t *file = NULL;
    char *input_champion = parsing_parse_file("../tests/utils/champions/src/bad_word.s");

    file = file_new(input_champion);
    cr_assert_null(parsing_champion_header(file));
}

Test(parsing_of_champion, file_not_exist)
{
    cr_assert_null(parsing_parse_file("not exist"));
}
