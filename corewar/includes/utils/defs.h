/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** defs
*/

#pragma once

// Represent a utils for champion fighter
typedef struct s_utils_fighter {
    char *file;         // Champion File
    int load_address;   // Sets the next program’s loading address
    int prog_number;    // Sets the next program’s number.
} utils_fighter_t;
