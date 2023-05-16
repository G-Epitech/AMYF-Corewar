/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** asm parsing
*/

#include <stddef.h>
#include "common/include/utils/malloc2.h"

static void str_concat(char *destination, char *source)
{
    size_t len_destination = 
}

char *parse_file(char *file_path)
{
    char *new_input_champion = NULL;
    char *new_line_input_champion = malloc2(sizeof(char) * 1);
    size_t input_len = 0;

    new_line_input_champion[0] = '\0'; 
    while (getline(&new_line_input_champion, &input_len, file_path) != -1) {
        str_concat(new_input_champion, new_line_input_champion);
    }
    return NULL;
}
