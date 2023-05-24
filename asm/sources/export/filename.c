/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** Corewar / Export / Filename
*/

#include <stdlib.h>
#include <stdbool.h>
#include "export/defs.h"
#include "my/includes/my.h"
#include "common/includes/utils/malloc2.h"

static int get_start_of_filename(char *src_file, int len)
{
    int i = len - 1;

    while (i > 0 && src_file[i] != '/')
        i -= 1;
    if (src_file[i] == '/')
        i += 1;
    return i;
}

static int get_end_of_filename(char *src_file, int len)
{
    int i = len - 1;

    if (src_file[i] != 's')
        return 0;
    i -= 1;
    if (i < 0 || src_file[i] != '.')
        return 0;
    return 2;
}

char *asm_export_get_file_name(char *src_file)
{
    int total_len = my_strlen(src_file);
    char *start = src_file + get_start_of_filename(src_file, total_len);
    int filename_with_ext_len = my_strlen(start);
    int filename_without_ext_len = filename_with_ext_len;
    char *filename = NULL;

    filename_without_ext_len -= get_end_of_filename(src_file, total_len);
    filename = malloc2(filename_without_ext_len + ASM_EXPORT_EXT_LEN + 1);
    if (!filename)
        return NULL;
    my_strncpy(filename, start, filename_without_ext_len);
    my_strcpy(filename + filename_without_ext_len, ASM_EXPORT_EXT);
    return filename;
}
