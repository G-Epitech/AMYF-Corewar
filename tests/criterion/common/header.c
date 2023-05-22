/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** header
*/

#include <criterion/criterion.h>
#include "header/header.h"
#include "utils/malloc2.h"

Test(header_functions, new_header) {
    header_t *header = header_new();

    cr_assert_not_null(header);
    cr_assert_eq(header->name[0], '\0');
    cr_assert_eq(header->comment[0], '\0');
    cr_assert_eq(header->body_size, 0);
    header_free(header);
}

Test(header_functions, new_header_malloc_fail) {
    header_t *header = NULL;

    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_FAIL);
    header = header_new();
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_NORMAL);
    cr_assert_null(header);
}

Test(header_functions, free_fail) {
    header_free(NULL);
}
