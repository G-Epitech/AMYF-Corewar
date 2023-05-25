/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** Corewar / Tests / Assembler / Export / Cmd / Get by index
*/

#include <criterion/criterion.h>
#include "export/export.h"
#include "common/includes/op/defs.h"
#include "common/includes/cmd/cmd.h"
#include "common/includes/list/list.h"
#include "common/includes/node/node.h"

Test(asm_export_get_cmd_by_index_tests, basic)
{
    cmd_t *cmd1 = cmd_new();
    cmd_t *cmd2 = cmd_new();
    cmd_t *cmd3 = cmd_new();
    cmd_t *cmd4 = cmd_new();
    cmd_t *cmd5 = cmd_new();
    list_t *cmds = list_new();

    cmd1->index_cmd = 10;
    cmd1->parameters[0] = (parameter_t) {0x1, T_REG};
    cmd1->parameters[1] = (parameter_t) {4, T_DIR | T_LAB};
    cmd1->parameters[2] = (parameter_t) {0x1, T_DIR};

    cmd2->index_cmd = 11;
    cmd2->parameters[0] = (parameter_t) {0x16, T_DIR};

    cmd3->index_cmd = 1;
    cmd3->parameters[0] = (parameter_t) {0x64, T_DIR};
    cmd3->parameters[1] = (parameter_t) {0x4, T_REG};

    cmd4->index_cmd = 1;
    cmd4->parameters[0] = (parameter_t) {0x2, T_DIR};
    cmd4->parameters[1] = (parameter_t) {0x5, T_REG};

    cmd5->index_cmd = 0;
    cmd5->parameters[0] = (parameter_t) {0x1, T_DIR};

    list_append(cmds, node_new(NODE_DATA_FROM_PTR(cmd1)));
    list_append(cmds, node_new(NODE_DATA_FROM_PTR(cmd2)));
    list_append(cmds, node_new(NODE_DATA_FROM_PTR(cmd3)));
    list_append(cmds, node_new(NODE_DATA_FROM_PTR(cmd4)));
    list_append(cmds, node_new(NODE_DATA_FROM_PTR(cmd5)));
    cr_assert(asm_export_get_cmd_by_index(0, cmds) == cmd1);
    cr_assert(asm_export_get_cmd_by_index(3, cmds) == cmd4);
    cr_assert(asm_export_get_cmd_by_index(4, cmds) == cmd5);
    cr_assert_null(asm_export_get_cmd_by_index(45, cmds));
    list_free(cmds, &cmd_node_freer);
}

Test(asm_export_get_cmd_by_index_tests, null_list)
{
    cr_assert_null(asm_export_get_cmd_by_index(45, NULL));
}
