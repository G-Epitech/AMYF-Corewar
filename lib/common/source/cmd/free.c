/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** free
*/

#include <stdlib.h>
#include "cmd/defs.h"

void cmd_free(cmd_t *cmd)
{
    if (!cmd)
        return;
    free(cmd);
}
