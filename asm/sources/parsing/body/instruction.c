/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** asm parsing body instruction
*/

#include "parsing/utils.h"
#include "my/includes/my.h"
#include "parsing/parsing.h"
#include "common/includes/cmd/cmd.h"
#include "common/includes/list/list.h"
#include "common/includes/header/header.h"
#include "common/includes/utils/malloc2.h"
#include "common/includes/champion/champion.h"

cmd_handler_t *cmd_handler_new(void)
{
    cmd_handler_t *new = malloc2(sizeof(cmd_handler_t));

    if (!new)
        return NULL;
    new->status_label = true;
    new->temp_name_label = NULL;
    return new;
}

static bool have_label(char **line_separed, cmd_t **cmd,
int *index_line, cmd_handler_t *cmd_handler)
{
    char **args1_separed =
    str_to_word_array(line_separed[*index_line], ": \t");

    if (line_separed[1] == NULL) {
        cmd_handler->status_label = false;
        cmd_handler->temp_name_label = my_strdup(args1_separed[0]);
    } else {
        (*index_line)++;
        *cmd = cmd_new(line_separed[*index_line]);
        if ((*cmd) == NULL)
            return false;
        (*cmd)->label = my_strdup(args1_separed[0]);
    }
    return true;
}

static bool no_have_label(char **line_separed, cmd_t **cmd,
int *index_line, cmd_handler_t *cmd_handler)
{
    if (cmd_handler->status_label == false) {
        *cmd = cmd_new(line_separed[*index_line]);
        if ((*cmd) == NULL)
            return false;
        (*cmd)->label = my_strdup(cmd_handler->temp_name_label);
        cmd_handler->status_label = true;
    } else {
        *cmd = cmd_new(line_separed[*index_line]);
        if ((*cmd) == NULL)
            return false;
        (*cmd)->label = NULL;
    }
    return true;
}

bool parsing_instruction(char **line_separed, cmd_t **cmd,
int *index_line, cmd_handler_t *cmd_handler)
{
    if (my_strstr(line_separed[0], ":") != NULL) {
        if (!have_label(line_separed, cmd, index_line, cmd_handler))
            return false;
    } else {
        if (!no_have_label(line_separed, cmd, index_line, cmd_handler))
            return false;
    }
    (*index_line)++;
    return true;
}
