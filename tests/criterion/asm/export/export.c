/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** Tests of assembler file exportation
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
#include "common/includes/champion/champion.h"

Test(asm_export_tests, basic)
{
    int file = ASM_EXPORT_NULL_FD;
    champion_t *champion = champion_new();

    cmd_t *cmd1 = cmd_new();
    cmd_t *cmd2 = cmd_new();
    champion->body = list_new();
    champion->header = header_new();

    strcpy(champion->header->name, "Bill");
    strcpy(champion->header->comment, "1Equilibre");
    cmd1->index_cmd = 1;
    cmd1->parameters[0] = (parameter_t) {0x2, T_DIR};
    cmd1->parameters[1] = (parameter_t) {0x5, T_REG};
    cmd2->index_cmd = 0;
    cmd2->label = strdup("live");
    cmd2->parameters[0] = (parameter_t) {0x1, T_DIR};
    list_append(champion->body, node_new(NODE_DATA_FROM_PTR(cmd1)));
    list_append(champion->body, node_new(NODE_DATA_FROM_PTR(cmd2)));

    cr_assert(asm_export_prepare(champion->header, champion->body));
    cr_assert_eq(champion->header->body_size,
    (DIR_SIZE + REG_SIZE + OP_SIZE + PROTO_SIZE + OP_SIZE + DIR_SIZE));
    cr_assert(cmd2->body_pos == DIR_SIZE + PROTO_SIZE + REG_SIZE + 2 * OP_SIZE);
    cr_assert(asm_export_champion("champion2.s", champion));
    file = open("champion2.cor", O_WRONLY);
    cr_assert(file != ASM_EXPORT_NULL_FD);
    if (file != ASM_EXPORT_NULL_FD)
        close(file);
    champion_free(champion);
    remove("champion2.cor");
}

Test(asm_export_tests, with_null_filename)
{
    champion_t *champion = champion_new();

    cr_assert_not(asm_export_champion(NULL, champion));
    champion_free(champion);
}

Test(asm_export_tests, with_null_champion)
{
    cr_assert_not(asm_export_champion("champion3.cor", NULL));
}

Test(asm_export_tests, with_open_fail)
{
    struct rlimit save;
    struct rlimit limit;
    champion_t *champion = champion_new();
    cmd_t *cmd1 = cmd_new();
    champion->body = list_new();
    champion->header = header_new();

    strcpy(champion->header->name, "Bill");
    strcpy(champion->header->comment, "1Equilibre");
    cmd1->index_cmd = 1;
    cmd1->parameters[0] = (parameter_t) {0x2, T_DIR};
    cmd1->parameters[1] = (parameter_t) {0x5, T_REG};

    list_append(champion->body, node_new(NODE_DATA_FROM_PTR(cmd1)));
    getrlimit(RLIMIT_NOFILE, &limit);
    getrlimit(RLIMIT_NOFILE, &save);
    limit.rlim_cur = 1;
    setrlimit(RLIMIT_NOFILE, &limit);
    cr_assert_not(asm_export_champion("champion5.cor", champion));
    setrlimit(RLIMIT_NOFILE, &save);
    champion_free(champion);
}

Test(asm_export_tests, with_null_command_in_body)
{
    champion_t *champion = champion_new();
    cmd_t *cmd1 = cmd_new();
    champion->body = list_new();
    champion->header = header_new();

    strcpy(champion->header->name, "Bill");
    strcpy(champion->header->comment, "1Equilibre");
    cmd1->index_cmd = 1;
    cmd1->parameters[0] = (parameter_t) {0x2, T_DIR};
    cmd1->parameters[1] = (parameter_t) {0x5, T_REG};

    list_append(champion->body, node_new(NODE_DATA_FROM_PTR(cmd1)));
    list_append(champion->body, node_new(NODE_DATA_FROM_PTR(NULL)));
    cr_assert(!asm_export_champion("champion12.cor", champion));
    champion_free(champion);
}
