/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** Tests of assembler file exportation for filename
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/resource.h>
#include <criterion/criterion.h>
#include "export/defs.h"
#include "export/export.h"
#include "common/includes/node/node.h"
#include "common/includes/list/list.h"
#include "common/includes/header/header.h"
#include "common/includes/utils/malloc2.h"
#include "common/includes/champion/champion.h"

Test(asm_export_get_file_name_tests, basic_s_file)
{
    char *input_file = "bill.s";
    char *out = asm_export_get_file_name(input_file);

    cr_assert_str_eq(out, "bill.cor");
    free(out);
}

Test(asm_export_get_file_name_tests, file_no_s_extension)
{
    char *input_file = "bill.superfile";
    char *out = asm_export_get_file_name(input_file);

    cr_assert_str_eq(out, "bill.superfile.cor");
    free(out);
}

Test(asm_export_get_file_name_tests, basic_s_file_with_path)
{
    char *input_file = "../folder/bill.s";
    char *out = asm_export_get_file_name(input_file);

    cr_assert_str_eq(out, "bill.cor");
    free(out);
}

Test(asm_export_get_file_name_tests, file_with_extension_sevral_letters)
{
    char *input_file = "../folder/bill.docx";
    char *out = asm_export_get_file_name(input_file);

    cr_assert_str_eq(out, "bill.docx.cor");
    free(out);
}

Test(asm_export_get_file_name_tests, file_with_extension_ending_with_ss)
{
    char *input_file = "../folder/bill.sass";
    char *out = asm_export_get_file_name(input_file);

    cr_assert_str_eq(out, "bill.sass.cor");
    free(out);
}

Test(asm_export_get_file_name_tests, malloc_fail)
{
    char *input_file = "bill.s";

    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_FAIL);
    cr_assert_null(asm_export_get_file_name(input_file));
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_NORMAL);
}

Test(asm_export_get_file_name_tests, just_one_letter)
{
    char *input_file = "s";
    char *out = asm_export_get_file_name(input_file);

    cr_assert_str_eq(out, "s.cor");
    free(out);
}
