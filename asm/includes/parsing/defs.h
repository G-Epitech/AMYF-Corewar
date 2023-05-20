/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** defs
*/

#pragma once

#include <stdio.h>
#include <stddef.h>
#include <stdint.h>

typedef struct s_list list_t;

// Represent the file passed in parameter.
typedef struct s_file {
    size_t index_line;          // Index lines
    char **lines;               // All line to treate
} file_t;

// Represent the label
typedef struct s_label {
    char *name;         // Label name
    int line;           // Line where is the label
} label_t;

// Represent the handler of label parsing.
typedef struct s_label_handler {
    list_t *labels;                 // List of labels
    int line_parsing;               // Index of body parsing
    int index_cmd;                  // Represents index of command
    bool status_label;              // Represent status of parsing
    char *temp_name_label;          // Represent the temporair name of label
} label_handler_t;

// Represent the handler of label parsing.
typedef struct s_cmd_handler {
    bool status_label;              // Represent status of parsing
    char *temp_name_label;          // Represent the temporair name of label
} cmd_handler_t;

// Represent the parametre handler
typedef struct s_param_handler {
    bool status_param;              // Represent status of param treated
    int index_param;                // Represent the index of param to treat
} param_handler_t;
