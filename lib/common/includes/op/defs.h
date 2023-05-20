/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** defs
*/

#pragma once

#include "common/includes/cmd/defs.h"

#define T_NULL 0
#define T_REG 1
#define T_DIR 2
#define T_IND 4
#define T_LAB 8

#define IS_T_REG(p) (p & T_REG)
#define IS_T_DIR(p) (p & T_DIR)
#define IS_T_IND(p) (p & T_IND)
#define IS_T_LAB(p) (p & T_LAB)
#define IS_T_VALID(type, proto) (proto & type)

#define OP_SIZE 1
#define IND_SIZE 2
#define DIR_SIZE 4
#define REG_SIZE 1
#define PROTO_SIZE 1

// Represent a operator structure.
typedef struct op_s {
    char *mnemonique;            // Name of the command
    char nbr_args;               // Number of arguments
    char type[MAX_ARGS_NUMBER];  // Types of arguments
    char code;                   // Id of the command
    int nbr_cycles;              // Number of cycles
} op_t;

extern const op_t op_tab[];
extern const op_t op_tab_health[];
