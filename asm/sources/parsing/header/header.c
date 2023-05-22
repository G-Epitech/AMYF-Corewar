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
        status_parsing = parsing_header_get_info(copy_line, new_header);
        if (check_status(status_parsing, &filled))
            return NULL;
        file->index_line++;
    }
    return new_header;
}
