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

#include <stdio.h>
#include <stdlib.h>

char* my_inttostr(int number)
{
    char *str = NULL;
    int temp = number;
    int length = 0;
    bool neg = false;

    if (temp < 0) {
        length += 1;
        neg = true;
        temp *= -1;
        number *= -1;
    }
    if (temp == 0) {
        length = 1;
    } else {
        while (temp != 0) {
            temp /= 10;
            length += 1;
        }
    }
    str = malloc(sizeof(char) * (length + 1));
    if (!str)
        return NULL;
    my_memset(str, '\0', length + 1);
    if (neg)
        str[0] = '-';
    while (length > neg) {
        str[--length] = '0' + (number % 10);
        number /= 10;
    }
    return str;
}

static void write_header(int fd, champion_t *champion)
{
    write(fd, ".name \"", 7);
    write(fd, champion->header->name, my_strlen(champion->header->name));
    write(fd, "\"\n.comment \"", 12);
    write(fd, champion->header->comment, my_strlen(champion->header->comment));
    write(fd, "\"\n\n", 3);
}

void write_body(int fd, champion_t *champion)
{
    node_t *tmp = champion->body->first;
    cmd_t *cmd = NULL;
    char *str = NULL;

    while (tmp) {
        cmd = NODE_DATA_TO_PTR(tmp->data, cmd_t *);
        write(fd, op_tab[cmd->index_cmd].mnemonique, my_strlen(op_tab[cmd->index_cmd].mnemonique));
        write(fd, " ", 1);
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
        write(fd, "\n", 1);
        tmp = tmp->next;
    }
}

int corewar_dessassembler(char *file)
{
    champion_t *champion = parsing_champion(file);
    int fd = 0;

    fd = open("champion.s", O_TRUNC | O_CREAT | O_WRONLY, 0644);
    write_header(fd, champion);
    write_body(fd, champion);
    my_printf("Addr: %d\n", arena_get_real_addr(MEM_SIZE));
    return 0;
}
