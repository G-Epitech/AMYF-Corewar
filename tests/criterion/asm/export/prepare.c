/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** Corewar / Tests / Assembler / Export / Prepare
*/

#include <criterion/criterion.h>
#include "export/export.h"
#include "my/includes/my.h"
#include "parsing/parsing.h"
#include "common/includes/op/defs.h"
#include "common/includes/node/node.h"
#include "common/includes/list/list.h"
#include "common/includes/header/header.h"
#include "common/includes/champion/champion.h"

Test(asm_export_prepare_tests, basic)
{
    cmd_t *cmd1 = cmd_new();
    cmd_t *cmd2 = cmd_new();
    list_t *commands = list_new();
    header_t *header = header_new();

    cmd1->index_cmd = 1;
    cmd1->parameters[0] = (parameter_t) {0x2, T_DIR};
    cmd1->parameters[1] = (parameter_t) {0x5, T_REG};
    cmd2->index_cmd = 0;
    cmd2->label = my_strdup("live");
    cmd2->parameters[0] = (parameter_t) {0x1, T_DIR};
    list_append(commands, node_new(NODE_DATA_FROM_PTR(cmd1)));
    list_append(commands, node_new(NODE_DATA_FROM_PTR(cmd2)));

    cr_assert(asm_export_prepare(header, commands));
    cr_assert(header->body_size == (DIR_SIZE + REG_SIZE + OP_SIZE + PROTO_SIZE + OP_SIZE + DIR_SIZE));
    cr_assert(cmd2->body_pos == DIR_SIZE + PROTO_SIZE + REG_SIZE + 2 * OP_SIZE);
    cmd_free(cmd1);
    cmd_free(cmd2);
    list_free(commands, NULL);
}

Test(asm_export_prepare_tests, with_null_cmd)
{
    cmd_t *cmd1 = cmd_new();
    cmd_t *cmd2 = cmd_new();
    list_t *commands = list_new();
    header_t *header = header_new();

    cmd1->index_cmd = 1;
    cmd1->parameters[0] = (parameter_t) {0x2, T_DIR};
    cmd1->parameters[1] = (parameter_t) {0x5, T_REG};
    cmd2->index_cmd = 0;
    cmd2->label = my_strdup("live");
    cmd2->parameters[0] = (parameter_t) {0x1, T_DIR};
    list_append(commands, node_new(NODE_DATA_FROM_PTR(cmd1)));
    list_append(commands, node_new(NODE_DATA_FROM_PTR(NULL)));
    list_append(commands, node_new(NODE_DATA_FROM_PTR(cmd2)));
    cr_assert(!asm_export_prepare(header, commands));
    cmd_free(cmd1);
    cmd_free(cmd2);
    list_free(commands, NULL);
}

Test(asm_export_prepare_tests, with_null_header)
{
    list_t *commands = list_new();

    cr_assert(!asm_export_prepare(NULL, commands));
    list_free(commands, NULL);
}

Test(asm_export_prepare_tests, with_null_commands_list)
{
    header_t *header = header_new();

    cr_assert(!asm_export_prepare(header, NULL));
    header_free(header);
}
