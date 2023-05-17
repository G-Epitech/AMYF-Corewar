/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** asm parsing header
*/

#include "parsing/utils.h"
#include "my/includes/my.h"
#include "parsing/parsing.h"
#include "common/includes/cmd/cmd.h"
#include "common/includes/header/header.h"
#include "common/includes/champion/champion.h"

static void free_tabs(char **line_separed_space,
char **line_separed_comment)
{
    free(line_separed_space);
    free(line_separed_comment);
}

static int get_info_champion(char *line_champion, header_t *new_header)
{
    char **line_separed_space = str_to_word_array(line_champion, " \t");
    char **line_separed_comment = str_to_word_array(line_champion, "\"");

    if (my_strcmp(line_separed_space[0], ".name") == 0) {
        if (my_strlen(line_separed_comment[1]) > HEADER_NAME)
            return PARSING_ERROR;
        my_strcpy(new_header->name, line_separed_comment[1]);
        free_tabs(line_separed_space, line_separed_comment);
        return PARSING_NAME;
    }
    if (my_strcmp(line_separed_space[0], ".comment") == 0) {
        if (my_strlen(line_separed_comment[1]) > HEADER_COMMENT)
            return PARSING_ERROR;
        my_strcpy(new_header->comment, line_separed_comment[1]);
        free_tabs(line_separed_space, line_separed_comment);
        return PARSING_COMMENT;
    }
    free_tabs(line_separed_space, line_separed_comment);
    return PARSING_ERROR;
}

static bool parsing_wrong_line(file_t *file)
{
    if (parsing_is_empty(file->lines[file->index_line])) {
        file->index_line++;
        return true;
    }
    if (parsing_is_comment(file->lines[file->index_line])) {
        file->index_line++;
        return true;
    }
    return false;
}

static bool check_status(int status_parsing, bool *filled)
{
    if (status_parsing == PARSING_COMMENT) {
        (*filled) = true;
        return false;
    } else if (status_parsing == PARSING_NAME) {
        return false;
    } else {
        return true;
    }
}

header_t *parsing_champion_header(file_t *file)
{
    header_t *new_header = header_new();
    bool filled = false;
    char *copy_line = NULL;
    int status_parsing = 0;

    while (!filled) {
        if (file->lines[file->index_line] == NULL)
            return NULL;
        if (parsing_wrong_line(file))
            continue;
        copy_line = my_strdup(file->lines[file->index_line]);
        copy_line = parsing_filter_comment(copy_line);
        status_parsing = get_info_champion(copy_line, new_header);
        if (check_status(status_parsing, &filled))
            return NULL;
        file->index_line++;
    }
    return new_header;
}
