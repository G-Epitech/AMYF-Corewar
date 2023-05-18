/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** cmd
*/

#include <criterion/theories.h>
#include <criterion/criterion.h>
#include "cmd/cmd.h"
#include "utils/malloc2.h"

Test(commands_functions, new_command) {
    cmd_t *cmd = cmd_new();

    cr_assert_not_null(cmd);
    cr_assert_null(cmd->label);
    for (size_t i = 0; i < MAX_ARGS_NUMBER; i++)
        cr_assert_eq(cmd->parameters[i].type, P_NULL);
    cmd_free(cmd);
}

Test(commands_functions, new_command_malloc_fail) {
    cmd_t *cmd = NULL;

    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_FAIL);
    cmd = cmd_new();
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_NORMAL);
    cr_assert_null(cmd);
}

TheoryDataPoints(commands_functions, append_param) = {
    DataPoints(int, -100, -1, 0, 100, 10000),
    DataPoints(type_parameter_t, P_NULL, P_REGISTER, P_DIRECT, P_INDIRECT)
};

Theory((int value, type_parameter_t type), commands_functions, append_param) {
    cmd_t *cmd = cmd_new();

    cr_assert(cmd_append_parameter(cmd, (parameter_t) {value, type}));
    cr_assert_eq(cmd->parameters[0].type, type);
    cr_assert_eq(cmd->parameters[0].value, value);
    cmd_free(cmd);
}

Test(commands_functions, append_param_null) {
    cmd_t *cmd = NULL;
    bool status = cmd_append_parameter(cmd, (parameter_t) {0, 0});

    cr_assert(!status);
}

Test(commands_functions, append_param_multi) {
    cmd_t *cmd = cmd_new();
    bool status = true;

    status = cmd_append_parameter(cmd, (parameter_t) {0, P_DIRECT});
    cr_assert(status);
    cr_assert_eq(cmd->parameters[0].value, 0);
    status = cmd_append_parameter(cmd, (parameter_t) {1, P_DIRECT});
    cr_assert(status);
    cr_assert_eq(cmd->parameters[1].value, 1);
    status = cmd_append_parameter(cmd, (parameter_t) {2, P_DIRECT});
    cr_assert(status);
    cr_assert_eq(cmd->parameters[2].value, 2);
    status = cmd_append_parameter(cmd, (parameter_t) {3, P_DIRECT});
    cr_assert(status);
    cr_assert_eq(cmd->parameters[3].value, 3);
    status = cmd_append_parameter(cmd, (parameter_t) {4, P_DIRECT});
    cr_assert(!status);
    cmd_free(cmd);
}

Test(commands_functions, free_null) {
    cmd_free(NULL);
}
