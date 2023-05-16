/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** defs
*/

#pragma once

// Represent the file passed in parameter
typedef struct s_file {
    size_t index_line;          // Index lines
    char **lines;               // All line to treate
} file_t;
