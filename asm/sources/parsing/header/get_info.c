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

static bool parsing_get_name(char **line_wh_comment,
char **line_wh_space, header_t *new_header)
{
    int last_word = 0;

    if (line_wh_space[1][0] != '\"')
        return false;
    while (line_wh_space[last_word + 1] != NULL)
        last_word++;
    if (line_wh_space[last_word][my_strlen(line_wh_space[last_word]) - 1]
    != '\"') {
        return false;
    }
    if (my_strlen(line_wh_comment[1]) > HEADER_NAME_SIZE)
        return false;
    my_strcpy(new_header->name, line_wh_comment[1]);
    free_tabs(line_wh_space, line_wh_comment);
    return true;
}

static bool parsing_get_comment(char **line_wh_comment,
char **line_wh_space, header_t *new_header)
{
    int last_word = 0;

    if (line_wh_space[1][0] != '\"')
        return false;
    while (line_wh_space[last_word + 1] != NULL)
        last_word++;
    if (line_wh_space[last_word][my_strlen(line_wh_space[last_word]) - 1]
    != '\"') {
        return false;
    }
    if (my_strlen(line_wh_comment[1]) > HEADER_COMMENT_SIZE)
        return false;
    my_strcpy(new_header->comment, line_wh_comment[1]);
    free_tabs(line_wh_space, line_wh_comment);
    return true;
}

int parsing_header_get_info(char *line_champion, header_t *new_header)
{
    char **line_wh_space = str_to_word_array(line_champion, " \t");
    char **line_wh_comment = str_to_word_array(line_champion, "\"");

    if (my_strcmp(line_wh_space[0], ".name") == 0) {
        if (!parsing_get_name(line_wh_comment, line_wh_space, new_header))
            return PARSING_ERROR;
        return PARSING_NAME;
    }
    if (my_strcmp(line_wh_space[0], ".comment") == 0) {
        if (!parsing_get_comment(line_wh_comment, line_wh_space, new_header))
            return PARSING_ERROR;
        return PARSING_COMMENT;
    }
    free_tabs(line_wh_space, line_wh_comment);
    return PARSING_ERROR;
}
