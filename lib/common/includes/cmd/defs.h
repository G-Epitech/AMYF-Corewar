/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** defs
*/

#pragma once

#define MAX_ARGS_NUMBER 4

// Represent a parameter of a command.
typedef struct s_parameter {
    int value;      // Value of the parameter
    char type;      // Type of the parameter
} parameter_t;

// Represent a command.
typedef struct s_cmd {
    unsigned int index_cmd;                     // Index of the operator array
    parameter_t parameters[MAX_ARGS_NUMBER];    // Parameters of the command
    char *label;                                // Label of the command
} cmd_t;
