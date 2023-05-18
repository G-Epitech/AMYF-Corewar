/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** asm parsing body
*/

#include "parsing/utils.h"
#include "my/includes/my.h"
#include "parsing/parsing.h"
#include "common/includes/cmd/cmd.h"
#include "common/includes/list/list.h"
#include "common/includes/header/header.h"
#include "common/includes/champion/champion.h"

static bool get_info_body_champion(char *line_champion, cmd_t *cmd)
{
    char **line_separed = str_to_word_array(line_champion, " \t,");

    (void) cmd;
    for (int index = 0; line_separed[index] != NULL; index++) {
        printf("args : [%s] | ", line_separed[index]);
    }
    printf("\n");
    return true;
}

bool parsing_cmd(file_t *file, champion_t *champion)
{
    char *copy_line = NULL;
    cmd_t *cmd = NULL;

    copy_line = my_strdup(file->lines[file->index_line]);
    copy_line = parsing_filter_comment(copy_line);
    if (!get_info_body_champion(copy_line, cmd))
        return false;
    champion_append_cmd(champion, cmd);
    file->index_line++;
    return true;
}

bool parsing_champion_body(file_t *file, champion_t *champion)
{
    list_t *champion_cmds = list_new();
    label_handler_t *handler = label_handler_new();
    bool filled = false;

    if (!champion_cmds)
        return false;
    if (!find_label(handler, file))
        return false;

    node_t *temp = handler->labels->first;

    while (temp) {
        printf("Nb line : [%i] | [%s] : name\n", NODE_DATA_TO_PTR(temp->data, label_t *)->line, NODE_DATA_TO_PTR(temp->data, label_t *)->name);
        temp = temp->next;
    }
    (void) filled;
    (void) champion;
    // while (!filled) {
    //     if (file->lines[file->index_line] == NULL)
    //         return NULL;
    //     if (parsing_wrong_line(file))
    //         continue;
    //     if (!parsing_cmd(file, champion))
    //         return false; 
    // }
    return champion_cmds;
}
