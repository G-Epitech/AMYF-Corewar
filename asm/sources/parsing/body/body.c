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

static bool get_info_body_champion(char *line_champion,
cmd_t **cmd, cmd_handler_t *cmd_handler, label_handler_t *label_handler)
{
    char **line_separed = str_to_word_array(line_champion, " \t,");
    int index_line = 0;

    if (!parsing_instruction(line_separed, cmd, &index_line, cmd_handler))
        return false;
    if (!parsing_arguments(line_separed, cmd, &index_line, label_handler))
        return false;
    return true;
}

bool parsing_cmd(file_t *file, champion_t *champion,
cmd_handler_t *cmd_handler, label_handler_t *label_handler)
{
    char *copy_line = NULL;
    cmd_t *cmd = NULL;

    copy_line = my_strdup(file->lines[file->index_line]);
    copy_line = parsing_filter_comment(copy_line);
    if (!get_info_body_champion(copy_line, &cmd, cmd_handler, label_handler))
        return false;
    champion_append_cmd(champion, cmd);
    file->index_line++;
    return true;
}

bool parsing_champion_body(file_t *file, champion_t *champion)
{
    label_handler_t *label_handler = label_handler_new();
    cmd_handler_t *cmd_handler = cmd_handler_new();

    champion->body = list_new();
    if (!champion->body)
        return false;
    if (!find_label(label_handler, file))
        return false;
    while (file->lines[file->index_line] != NULL) {
        if (parsing_wrong_line(file))
            continue;
        if (!parsing_cmd(file, champion, cmd_handler, label_handler))
            return false;
    }
    return true;
}
