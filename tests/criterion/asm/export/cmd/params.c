/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** Corewar / Tests / Assembler / Export / Cmd / Params
*/

#include <string.h>
#include <unistd.h>
#include <criterion/criterion.h>
#include "export/export.h"
#include "common/includes/op/defs.h"
#include "common/includes/cmd/cmd.h"
#include "common/includes/list/list.h"
#include "common/includes/node/node.h"
#include "common/includes/header/header.h"

static unsigned int read_int_as_big_endian(int fd)
{
    unsigned int nb = 0;
    unsigned char buffer = 0;

    for (int i = 0; i < 4; i++) {
        read(fd, &buffer, sizeof(char));
        nb = nb << 8;
        nb |= buffer;
    }
    return nb;
}

static unsigned short read_short_as_big_endian(int fd)
{
    unsigned short nb = 0;
    unsigned char buffer = 0;

    for (int i = 0; i < 2; i++) {
        read(fd, &buffer, sizeof(char));
        nb = nb << 8;
        nb |= buffer;
    }
    return nb;
}

static unsigned char read_char(int fd)
{
    unsigned char nb = 0;

    read(fd, &nb, sizeof(char));
    return nb;
}

static void cmd_node_freer(node_data_t data)
{
    cmd_free(NODE_DATA_TO_PTR(data, cmd_t *));
}

Test(asm_export_cmd_param_write_tests, basic_register)
{
    int file[2];
    char readed = 0;

    pipe(file);
    asm_export_cmd_param_write(3, T_REG, file[1]);
    close(file[1]);
    read(file[0], &readed, REG_SIZE);
    close(file[0]);
    cr_assert(readed == 3);
}

Test(asm_export_cmd_param_write_tests, basic_direct)
{
    int file[2];

    pipe(file);
    asm_export_cmd_param_write(156, T_DIR, file[1]);
    close(file[1]);
    cr_assert(read_int_as_big_endian(file[0]) == 156);
    close(file[0]);
}

Test(asm_export_cmd_param_write_tests, basic_indirect)
{
    int file[2];

    pipe(file);
    asm_export_cmd_param_write(34, T_IND, file[1]);
    close(file[1]);
    cr_assert(read_short_as_big_endian(file[0]) == 34);
    close(file[0]);
}

Test(asm_export_cmd_param_tests, basic)
{
    int file[2];
    cmd_t *cmd1 = cmd_new();
    cmd_t *cmd2 = cmd_new();
    cmd_t *cmd3 = cmd_new();
    cmd_t *cmd4 = cmd_new();
    cmd_t *cmd5 = cmd_new();
    list_t *cmds = list_new();
    header_t *header = header_new();

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

    cr_assert(asm_export_cmd_param(cmd1, 0, cmds, file[1]));
    cr_assert(asm_export_cmd_param(cmd1, 1, cmds, file[1]));
    close(file[1]);
    cr_assert(read_char(file[0]) == 0x1);
    cr_assert(read_short_as_big_endian(file[0]) == 0x18);
    close(file[0]);
    header_free(header);
    list_free(cmds, &cmd_node_freer);
}

Test(asm_export_cmd_param_tests, param_with_ref_to_null_cmd)
{
    cmd_t *cmd1 = cmd_new();
    list_t *cmds = list_new();
    header_t *header = header_new();

    strcpy(header->comment, "HI");
    strcpy(header->name, "Super");
    cmd1->index_cmd = 10;
    cmd1->parameters[0] = (parameter_t) {0x1, T_REG};
    cmd1->parameters[1] = (parameter_t) {4, T_DIR | T_LAB};
    cmd1->parameters[2] = (parameter_t) {0x1, T_DIR};

    list_append(cmds, node_new(NODE_DATA_FROM_PTR(cmd1)));
    asm_export_prepare(header, cmds);
    cr_assert_not(asm_export_cmd_param(cmd1, 1, cmds, 0));
    header_free(header);
    list_free(cmds, &cmd_node_freer);
}

Test(asm_export_cmd_get_labeled_param_tests, basic)
{
    cmd_t *cmd1 = cmd_new();
    cmd_t *cmd2 = cmd_new();
    cmd_t *cmd3 = cmd_new();
    cmd_t *cmd4 = cmd_new();
    cmd_t *cmd5 = cmd_new();
    cmd_t *cmd6 = cmd_new();
    list_t *cmds = list_new();
    header_t *header = header_new();
    int dist = 0;

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

    cmd6->index_cmd = 10;
    cmd6->parameters[0] = (parameter_t) {0x1, T_REG};
    cmd6->parameters[1] = (parameter_t) {12, T_DIR | T_LAB};
    cmd6->parameters[2] = (parameter_t) {0x1, T_DIR};

    list_append(cmds, node_new(NODE_DATA_FROM_PTR(cmd1)));
    list_append(cmds, node_new(NODE_DATA_FROM_PTR(cmd2)));
    list_append(cmds, node_new(NODE_DATA_FROM_PTR(cmd3)));
    list_append(cmds, node_new(NODE_DATA_FROM_PTR(cmd4)));
    list_append(cmds, node_new(NODE_DATA_FROM_PTR(cmd5)));
    list_append(cmds, node_new(NODE_DATA_FROM_PTR(cmd6)));
    asm_export_prepare(header, cmds);

    cr_assert(asm_export_cmd_get_labeled_param(
        &(cmd1->parameters[1]),
        cmd1->body_pos,
        &dist,
        cmds
    ));
    cr_assert(dist == 0x18);
    cr_assert(!asm_export_cmd_get_labeled_param(
        &(cmd6->parameters[1]),
        cmd1->body_pos,
        &dist,
        cmds
    ));
}
