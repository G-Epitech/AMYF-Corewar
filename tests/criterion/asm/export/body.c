/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** Tests of assembler file exportation
*/

#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <criterion/criterion.h>
#include "export/export.h"
#include "common/includes/op/defs.h"
#include "common/includes/cmd/cmd.h"
#include "common/includes/list/list.h"
#include "common/includes/node/node.h"
#include "common/includes/header/header.h"

Test(asm_export_champion_body_tests, basic)
{
    int file[2];
    header_t *header = header_new();
    cmd_t *cmd1 = cmd_new();
    cmd_t *cmd2 = cmd_new();
    cmd_t *cmd3 = cmd_new();
    cmd_t *cmd4 = cmd_new();
    cmd_t *cmd5 = cmd_new();
    list_t *cmds = list_new();

    strcpy(header->comment, "HI");
    strcpy(header->name, "Super");
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
    cmd5->label = strdup("live");
    cmd5->parameters[0] = (parameter_t) {0x1, T_DIR};

    list_append(cmds, node_new(NODE_DATA_FROM_PTR(cmd1)));
    list_append(cmds, node_new(NODE_DATA_FROM_PTR(cmd2)));
    list_append(cmds, node_new(NODE_DATA_FROM_PTR(cmd3)));
    list_append(cmds, node_new(NODE_DATA_FROM_PTR(cmd4)));
    list_append(cmds, node_new(NODE_DATA_FROM_PTR(cmd5)));
    asm_export_prepare(header, cmds);
    pipe(file);
    cr_assert(asm_export_champion_body(cmds, file[1]));
    close(file[0]);
    list_free(cmds, &cmd_node_freer);
}

Test(asm_export_champion_body_tests, with_fail_during_export_cmd)
{
    int file[2];
    header_t *header = header_new();
    cmd_t *cmd1 = cmd_new();
    cmd_t *cmd2 = cmd_new();
    cmd_t *cmd3 = cmd_new();
    cmd_t *cmd4 = cmd_new();
    cmd_t *cmd5 = cmd_new();
    list_t *cmds = list_new();

    strcpy(header->comment, "HI");
    strcpy(header->name, "Super");
    cmd1->index_cmd = 10;
    cmd1->parameters[0] = (parameter_t) {0x1, T_REG};
    cmd1->parameters[1] = (parameter_t) {56, T_DIR | T_LAB};
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
    cmd5->label = strdup("live");
    cmd5->parameters[0] = (parameter_t) {0x1, T_DIR};

    list_append(cmds, node_new(NODE_DATA_FROM_PTR(cmd1)));
    list_append(cmds, node_new(NODE_DATA_FROM_PTR(cmd2)));
    list_append(cmds, node_new(NODE_DATA_FROM_PTR(cmd3)));
    list_append(cmds, node_new(NODE_DATA_FROM_PTR(cmd4)));
    list_append(cmds, node_new(NODE_DATA_FROM_PTR(cmd5)));
    asm_export_prepare(header, cmds);
    pipe(file);
    cr_assert_not(asm_export_champion_body(cmds, file[1]));
    close(file[0]);
    list_free(cmds, &cmd_node_freer);
}

Test(asm_export_champion_body_tests, with_null_body)
{
    cr_assert_not(asm_export_champion_body(NULL, 1));
}