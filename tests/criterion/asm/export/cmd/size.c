/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** Corewar / Tests / Assembler / Export / Cmd / Size:
** Evaluate the total output size of a command
*/

#include <criterion/theories.h>
#include <criterion/criterion.h>
#include "export/export.h"
#include "common/includes/op/defs.h"
#include "common/includes/cmd/cmd.h"

Test(asm_export_cmd_size_get_proto_tests, need_proto)
{
    cmd_t *cmd = cmd_new();

    cmd->index_cmd = 10;
    cr_assert(asm_export_cmd_size_get_proto(cmd) == PROTO_SIZE);
    cmd_free(cmd);
}

Test(asm_export_cmd_size_get_proto_tests, not_need_proto)
{
    cmd_t *cmd = cmd_new();

    cmd->index_cmd = 0;
    cr_assert(asm_export_cmd_size_get_proto(cmd) == 0);
    cmd_free(cmd);
}

Test(asm_export_cmd_size_get_param_tests, size_of_reg)
{
    cr_assert(asm_export_cmd_size_get_param(T_REG, T_REG | T_IND) == REG_SIZE);
    cr_assert(asm_export_cmd_size_get_param(T_REG, T_REG | T_DIR) == REG_SIZE);
    cr_assert(asm_export_cmd_size_get_param(T_REG | T_LAB, T_REG) == REG_SIZE);
    cr_assert(asm_export_cmd_size_get_param(T_REG | T_LAB, T_REG | T_IND | T_DIR) == REG_SIZE);
}

Test(asm_export_cmd_size_get_param_tests, size_of_dir)
{
    cr_assert(asm_export_cmd_size_get_param(T_DIR, T_REG | T_IND | T_DIR) == DIR_SIZE);
    cr_assert(asm_export_cmd_size_get_param(T_DIR, T_REG | T_DIR) == DIR_SIZE);
    cr_assert(asm_export_cmd_size_get_param(T_DIR | T_LAB, T_DIR | T_IND) == DIR_SIZE);
}

Test(asm_export_cmd_size_get_param_tests, size_of_ind)
{
    cr_assert(asm_export_cmd_size_get_param(T_DIR, T_REG | T_IND) == IND_SIZE);
    cr_assert(asm_export_cmd_size_get_param(T_IND, T_REG | T_DIR) == IND_SIZE);
    cr_assert(asm_export_cmd_size_get_param(T_IND | T_LAB, T_DIR | T_IND) == IND_SIZE);
    cr_assert(asm_export_cmd_size_get_param(T_REG | T_LAB, T_DIR | T_IND) == IND_SIZE);
}

Test(asm_export_cmd_size_get_params_tests, size_of_sti_params)
{
    cmd_t *cmd = cmd_new();

    cmd->index_cmd = 10;
    cmd->parameters[0] = (parameter_t) {1, T_REG};
    cmd->parameters[1] = (parameter_t) {4, T_DIR | T_LAB};
    cmd->parameters[2] = (parameter_t) {1, T_DIR};
    cr_assert(asm_export_cmd_size_get_params(cmd) == 5);
}

Test(asm_export_cmd_size_get_params_tests, size_of_lld_params)
{
    cmd_t *cmd = cmd_new();

    cmd->index_cmd = 12;
    cmd->parameters[0] = (parameter_t) {1, T_DIR | T_LAB};
    cmd->parameters[1] = (parameter_t) {4, T_REG};
    cr_assert(asm_export_cmd_size_get_params(cmd) == (DIR_SIZE + REG_SIZE));
}

Test(asm_export_cmd_size_get_params_tests, size_of_ll_params)
{
    cmd_t *cmd = cmd_new();

    cmd->index_cmd = 12;
    cmd->parameters[0] = (parameter_t) {1, T_DIR | T_LAB};
    cmd->parameters[1] = (parameter_t) {4, T_REG};
    cr_assert(asm_export_cmd_size_get_params(cmd) == (DIR_SIZE + REG_SIZE));
}

Test(asm_export_cmd_size_eval_tests, size_of_sti_cmd)
{
    cmd_t *cmd = cmd_new();

    cmd->index_cmd = 10;
    cmd->parameters[0] = (parameter_t) {1, T_REG};
    cmd->parameters[1] = (parameter_t) {4, T_DIR | T_LAB};
    cmd->parameters[2] = (parameter_t) {1, T_DIR};
    cr_assert(asm_export_cmd_size_eval(cmd) == (OP_SIZE + PROTO_SIZE + REG_SIZE + IND_SIZE + IND_SIZE));
}
