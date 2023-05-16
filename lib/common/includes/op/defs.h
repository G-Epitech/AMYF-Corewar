/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** defs
*/

#pragma once

#include "common/includes/cmd/defs.h"

#define T_REG 1
#define T_DIR 2
#define T_IND 4

// Represent a operator structure.
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
