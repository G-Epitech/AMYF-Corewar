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
#include "common/includes/utils/malloc2.h"
#include "common/includes/champion/champion.h"

static bool parsing_label_wrong_line(file_t *file, int *label_index)
{
    if (parsing_is_empty(file->lines[*label_index])) {
        (*label_index)++;
        return true;
    }
    if (parsing_full_comment(file->lines[*label_index])) {
        (*label_index)++;
        return true;
    }
    return false;
}

static bool have_label(file_t *file, label_handler_t *handler,
label_t *new_label)
{
    char **line_separed = NULL;
    char *line = file->lines[handler->line_parsing];

    line_separed = str_to_word_array(line, ": \t");
    if (line_separed[1] == NULL) {
        handler->status_label = false;
        handler->temp_name_label = my_strdup(line_separed[0]);
        if (!parsing_body_label_check_existing(handler,
        handler->temp_name_label)) {
            return false;
        }
        return true;
    }
    new_label->name = my_strdup(line_separed[0]);
    new_label->line = handler->index_cmd;
    if (!parsing_body_label_check_existing(handler, new_label->name))
        return false;
    label_append(handler->labels, new_label);
    return true;
}

static bool no_have_label(label_handler_t *handler,
label_t *new_label)
{
    if (handler->status_label == false) {
        new_label->name = my_strdup(handler->temp_name_label);
        new_label->line = handler->index_cmd;
        if (!parsing_body_label_check_existing(handler, new_label->name))
            return false;
        label_append(handler->labels, new_label);
        handler->status_label = true;
    }
    return true;
}

static bool get_label(file_t *file, label_handler_t *handler)
{
    char *line = file->lines[handler->line_parsing];
    char **line_separed = str_to_word_array(line, " \t,");
    label_t *new_label = label_new();

    if (!new_label)
        return false;
    if (my_strstr(line_separed[0], ":") != NULL) {
        if (!have_label(file, handler, new_label))
            return false;
    } else {
        if (!no_have_label(handler, new_label))
            return false;
    }
    return true;
}

bool label_find(label_handler_t *handler, file_t *file)
{
    handler->line_parsing = file->index_line;
    while (file->lines[handler->line_parsing] != NULL) {
        if (parsing_label_wrong_line(file, &handler->line_parsing))
            continue;
        if (!get_label(file, handler))
            return false;
        handler->line_parsing++;
        if (handler->status_label == true)
            handler->index_cmd++;
    }
    return true;
}
