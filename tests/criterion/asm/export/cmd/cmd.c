/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** Corewar / Tests / Assembler / Export / Cmd
*/

#include <unistd.h>
#include <fcntl.h>
#include <criterion/criterion.h>
#include "export/export.h"
#include "my/includes/my.h"
#include "common/includes/op/defs.h"
#include "common/includes/cmd/cmd.h"
#include "common/includes/list/list.h"
#include "common/includes/node/node.h"
#include "common/includes/header/header.h"

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

Test(asm_export_cmd_tests, basic)
{
    int pseudofile[2];
    char readed = 0;
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
    cmd5->label = my_strdup("live");
    cmd5->parameters[0] = (parameter_t) {0x1, T_DIR};

    list_append(cmds, node_new(NODE_DATA_FROM_PTR(cmd1)));
    list_append(cmds, node_new(NODE_DATA_FROM_PTR(cmd2)));
    list_append(cmds, node_new(NODE_DATA_FROM_PTR(cmd3)));
    list_append(cmds, node_new(NODE_DATA_FROM_PTR(cmd4)));
    list_append(cmds, node_new(NODE_DATA_FROM_PTR(cmd5)));
    asm_export_prepare(header, cmds);
    pipe(pseudofile);
    cr_assert(asm_export_cmd(cmd1, cmds, pseudofile[1]));
    close(pseudofile[1]);
    read(pseudofile[0], &readed, OP_SIZE);
    cr_assert(readed == 11);
    read(pseudofile[0], &readed, PROTO_SIZE);
    cr_assert(readed == ((REG_PROTO << 6) | (IND_SIZE << 4) | (IND_SIZE << 2)));
    read(pseudofile[0], &readed, REG_SIZE);
    cr_assert(readed == 1);
    cr_assert(read_short_as_big_endian(pseudofile[0]) == 0x18);
    cr_assert(read_short_as_big_endian(pseudofile[0]) == 0x1);
    close(pseudofile[0]);
}


Test(asm_export_cmd_tests, cmd_and_null_body)
{
    cmd_t *cmd = cmd_new();

    cr_assert_not(asm_export_cmd(cmd, NULL, 1));
}

Test(asm_export_cmd_tests, null_cmd_and_body)
{
    list_t *cmds = list_new();

    cr_assert_not(asm_export_cmd(NULL, cmds, 1));
}

Test(asm_export_cmd_tests, null_cmd_and_null_body)
{
    cr_assert_not(asm_export_cmd(NULL, NULL, 1));
}
