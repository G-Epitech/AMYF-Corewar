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

int parsing_header_get_info(char *line_champion, header_t *new_header)
{
    char **line_separed_space = str_to_word_array(line_champion, " \t");
    char **line_separed_comment = str_to_word_array(line_champion, "\"");

    // for (int index = 0; line_separed_space[index] != NULL; index++) {
    //     printf("line_separed_space[%i] : [%s]\n", index, line_separed_space[index]);
    // }
    if (my_strcmp(line_separed_space[0], ".name") == 0) {
        if (my_strlen(line_separed_comment[1]) > HEADER_NAME_SIZE)
            return PARSING_ERROR;
        my_strcpy(new_header->name, line_separed_comment[1]);
        free_tabs(line_separed_space, line_separed_comment);
        return PARSING_NAME;
    }
    if (my_strcmp(line_separed_space[0], ".comment") == 0) {
        if (my_strlen(line_separed_comment[1]) > HEADER_COMMENT_SIZE)
            return PARSING_ERROR;
        my_strcpy(new_header->comment, line_separed_comment[1]);
        free_tabs(line_separed_space, line_separed_comment);
        return PARSING_COMMENT;
    }
    free_tabs(line_separed_space, line_separed_comment);
    return PARSING_ERROR;
}
