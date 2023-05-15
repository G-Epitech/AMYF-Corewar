/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** defs
*/

#pragma once

#define MAX_ARGS_NUMBER 4
#define T_REG 1
#define T_DIR 2
#define T_IND 4

typedef enum e_type_parameter {
    P_NULL = 0,
    P_REGISTER,
    P_DIRECT,
    P_INDIRECT
} type_parameter_t;

// Represent a parameter of a command.
typedef struct s_parameter {
    unsigned int value;     // Value of the parameter
    type_parameter_t type;  // Type of the parameter
} parameter_t;

// Represent a command.
typedef struct s_cmd {
    unsigned int index_cmd;                     // Index of the operator array
    parameter_t parameters[MAX_ARGS_NUMBER];    // Parameters of the command
    char *label;                                // Label of the command
} cmd_t;

// Represent a operator structure
typedef struct op_s {
   char *mnemonique;            // Name of the command
   char nbr_args;               // Number of arguments
   char type[MAX_ARGS_NUMBER];  // Types of arguments
   char code;                   // Id of the command
   int nbr_cycles;              // Number of cycles
} op_t;

op_t op_tab[] = {
    {"live", 1, {T_DIR}, 1, 10},
    {"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5},
    {"st", 2, {T_REG, T_IND | T_REG}, 3, 5},
    {"add", 3, {T_REG, T_REG, T_REG}, 4, 10},
    {"sub", 3, {T_REG, T_REG, T_REG}, 5, 10},
    {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6},
    {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6},
    {"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6},
    {"zjmp", 1, {T_DIR}, 9, 20},
    {"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25},
    {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25},
    {"fork", 1, {T_DIR}, 12, 800},
    {"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10},
    {"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50},
    {"lfork", 1, {T_DIR}, 15, 1000},
    {"aff", 1, {T_REG}, 16, 2},
    {0, 0, {0}, 0, 0}
};
