/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** new
*/

#include <stdlib.h>
#include "header/defs.h"
#include "utils/malloc2.h"

header_t *header_new(void)
{
    header_t *header = malloc2(sizeof(header_t));

    if (!header)
        return NULL;
    header->name = NULL;
    header->comment = NULL;
    return header;
}
