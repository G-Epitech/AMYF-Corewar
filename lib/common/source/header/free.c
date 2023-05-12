/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** free
*/

#include "header/defs.h"

void header_free(header_t *header)
{
    if (!header)
        return;
    free(header);
}
