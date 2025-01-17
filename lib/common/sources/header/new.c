/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** new
*/

#include <stdlib.h>
#include "header/defs.h"
#include "utils/malloc2.h"
#include "my/includes/my.h"

header_t *header_new(void)
{
    header_t *header = malloc2(sizeof(header_t));

    if (!header)
        return NULL;
    my_memset(&(header->name), '\0', HEADER_NAME_SIZE);
    my_memset(&(header->comment), '\0', HEADER_COMMENT_SIZE);
    header->body_size = 0;
    return header;
}
