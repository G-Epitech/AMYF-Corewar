/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** parsing
*/

#include <fcntl.h>
#include <unistd.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "parsing/parsing.h"
#include "common/includes/champion/champion.h"

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(parsing, champion_bill) {
    champion_t *champion = parsing_champion("../tests/utils/champions/bill.cor");

    cr_assert_not_null(champion);
    champion_free(champion);
}

Test(parsing, champion_pdf) {
    champion_t *champion = parsing_champion("../tests/utils/champions/pdf.cor");

    cr_assert_not_null(champion);
    champion_free(champion);
}

Test(parsing, champion_pdd) {
    champion_t *champion = parsing_champion("../tests/utils/champions/pdd.cor");

    cr_assert_not_null(champion);
    champion_free(champion);
}

Test(parsing, champion_white) {
    champion_t *champion = parsing_champion("../tests/utils/champions/white.cor");

    cr_assert_not_null(champion);
    champion_free(champion);
}

Test(parsing, empty) {
    champion_t *champion = parsing_champion(NULL);

    cr_assert_null(champion);
}

Test(parsing, unexisting_file) {
    champion_t *champion = parsing_champion("./ESRHDFJDFGSFDHGFDGHSDGNDFHGHDSGNBF");

    cr_assert_null(champion);
}

Test(parsing, wrong_file) {
    champion_t *champion = parsing_champion("../tests/utils/bin/asm");

    cr_assert_null(champion);
}

Test(parsing, read_short) {
    int fd = open("../tests/utils/champions/bill.cor", O_RDONLY);
    unsigned short test = parsing_read_short(fd);

    cr_assert(test == 0x00ea);
    close(fd);
}

Test(parsing, read_int) {
    int fd = open("../tests/utils/champions/bill.cor", O_RDONLY);
    unsigned int test = parsing_read_int(fd);

    cr_assert(test == 0x00ea83f3);
    close(fd);
}

Test(parsing, read_long_int) {
    int fd = open("../tests/utils/champions/bill.cor", O_RDONLY);
    unsigned long int test = parsing_read_long_int(fd);

    cr_assert(test == 0x00ea83f342696c6c);
    close(fd);
}

Test(parsing, read_char) {
    int fd = open("../tests/utils/champions/bill.cor", O_RDONLY);
    unsigned char test = parsing_read_char(fd);

    cr_assert(test == 0x00);
    close(fd);
}

Test(parsing, display_champion, .init=redirect_all_stdout) {
    champion_t *champion = parsing_champion("../tests/utils/champions/pdf.cor");

    parsing_display(champion);
    cr_assert_not_null(champion);
    champion_free(champion);
}

Test(parsing, display_null, .init=redirect_all_stdout) {
    champion_t *champion = NULL;

    parsing_display(champion);
    cr_assert_null(champion);
}

Test(parsing, display_empty_header, .init=redirect_all_stdout) {
    champion_t *champion = champion_new();

    parsing_display(champion);
    cr_assert_not_null(champion);
    champion_free(champion);
}
