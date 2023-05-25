/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** Corewar / Tests / Assembler / Export / Cmd / Get by index
*/

#include <unistd.h>
#include <criterion/criterion.h>
#include "export/export.h"
#include "common/includes/op/defs.h"
#include "common/includes/cmd/cmd.h"
#include "common/includes/list/list.h"
#include "common/includes/node/node.h"

Test(asm_export_cmd_proto_tests, basic_cmd)
{
    int file[2];
    cmd_t *cmd = cmd_new();
    char proto = (REG_PROTO << 6) | (DIR_PROTO << 4) | (IND_PROTO << 2);
    char readed = 0;

    cmd->index_cmd = 10;
    cmd->parameters[0] = (parameter_t) {0x1, T_REG};
    cmd->parameters[1] = (parameter_t) {4, T_DIR | T_LAB};
    cmd->parameters[2] = (parameter_t) {0x1, T_IND};
    pipe(file);
    cr_assert(asm_export_cmd_proto(cmd, file[1]));
    close(file[1]);
    read(file[0], &readed, PROTO_SIZE);
    close(file[0]);
    cr_assert_eq(readed, proto);
    cmd_free(cmd);
}

Test(asm_export_cmd_get_type_of_param_tests, dir_type)
{
    cr_assert(asm_export_cmd_get_type_of_param(T_DIR, T_DIR | T_IND | T_REG) == T_DIR);
    cr_assert(asm_export_cmd_get_type_of_param(T_DIR | T_LAB, T_DIR | T_REG) == T_DIR);
}

Test(asm_export_cmd_get_type_of_param_tests, reg_type)
{
    cr_assert(asm_export_cmd_get_type_of_param(T_REG, T_DIR | T_IND | T_REG) == T_REG);
    cr_assert(asm_export_cmd_get_type_of_param(T_REG, T_DIR | T_REG) == T_REG);
}

Test(asm_export_cmd_get_type_of_param_tests, ind_type)
{
    cr_assert(asm_export_cmd_get_type_of_param(T_DIR, T_IND | T_REG) == T_IND);
    cr_assert(asm_export_cmd_get_type_of_param(T_IND, T_DIR | T_IND | T_REG) == T_IND);
}
