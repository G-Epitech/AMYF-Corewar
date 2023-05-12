/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** defs
*/

#pragma once

#include "list/defs.h"
#include "header/defs.h"

// Represente a champion file data.
typedef struct s_champion {
    header_t *header;   // Informations of the champion
    list_t *body;       // Commands list of the champion
} champion_t;
