/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** desassembler
*/

#include <fcntl.h>
#include <unistd.h>
#include "arena/arena.h"
#include "my/includes/my.h"
#include "parsing/parsing.h"

static void write_header(int fd, champion_t *champion)
{
    write(fd, ".name \"", 7);
    write(fd, champion->header->name, my_strlen(champion->header->name));
    write(fd, "\"\n.comment \"", 12);
    write(fd, champion->header->comment, my_strlen(champion->header->comment));
    write(fd, "\"\n\n", 3);
}

static void write_cmd(int fd, cmd_t *cmd)
{
    char *str = NULL;

    for (int i = 0; i < op_tab[cmd->index_cmd].nbr_args; i++) {
        if (IS_T_REG(cmd->parameters[i].type))
            write(fd, " r", 2);
        if (IS_T_DIR(cmd->parameters[i].type))
            write(fd, " %", 2);
        if (IS_T_IND(cmd->parameters[i].type))
            write(fd, " ", 1);
        str = my_inttostr(cmd->parameters[i].value);
        write(fd, str, my_strlen(str));
        free(str);
    }
}

void write_body(int fd, champion_t *champion)
{
    node_t *tmp = champion->body->first;
    cmd_t *cmd = NULL;
    int len = 0;

    while (tmp) {
        cmd = NODE_DATA_TO_PTR(tmp->data, cmd_t *);
        len = my_strlen(op_tab[cmd->index_cmd].mnemonique);
        write(fd, op_tab[cmd->index_cmd].mnemonique, len);
        write(fd, " ", 1);
        write_cmd(fd, cmd);
        write(fd, "\n", 1);
        tmp = tmp->next;
    }
}

int corewar_dessassembler(char *file)
{
    champion_t *champion = parsing_champion(file);
    int fd = 0;

    fd = open("champion.d", O_TRUNC | O_CREAT | O_WRONLY, 0644);
    write_header(fd, champion);
    write_body(fd, champion);
    return 0;
}
