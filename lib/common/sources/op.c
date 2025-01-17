/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** Corewar / Lib / Common / Op
*/

#include <stdlib.h>
#include "op/defs.h"

const op_t op_tab[] = {
    {"live", 1, {T_DIR}, 1, 10, false},
    {"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, true},
    {"st", 2, {T_REG, T_IND | T_REG}, 3, 5, true},
    {"add", 3, {T_REG, T_REG, T_REG}, 4, 10, true},
    {"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, true},
    {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG},
    6, 6, true},
    {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
    7, 6, true},
    {"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
    8, 6, true},
    {"zjmp", 1, {T_IND}, 9, 20, false},
    {"ldi", 3, {T_REG | T_IND, T_IND | T_REG, T_REG}, 10, 25, true},
    {"sti", 3, {T_REG, T_REG | T_IND, T_IND | T_REG}, 11, 25, true},
    {"fork", 1, {T_IND}, 12, 800, false},
    {"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, true},
    {"lldi", 3, {T_REG | T_IND, T_IND | T_REG, T_REG}, 14, 50, true},
    {"lfork", 1, {T_IND}, 15, 1000, false},
    {"aff", 1, {T_REG}, 16, 2, true},
    {0, 0, {0}, 0, 0, false}
};

const op_t op_tab_health[] = {
    {"live", 1, {T_DIR}, 1, 10, false},
    {"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, true},
    {"st", 2, {T_REG, T_IND | T_REG}, 3, 5, true},
    {"add", 3, {T_REG, T_REG, T_REG}, 4, 10, true},
    {"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, true},
    {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG},
    6, 6, true},
    {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
    7, 6,true},
    {"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
    8, 6, true},
    {"zjmp", 1, {T_DIR}, 9, 20, false},
    {"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25, true},
    {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25, true},
    {"fork", 1, {T_DIR}, 12, 800, false},
    {"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, true},
    {"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50, true},
    {"lfork", 1, {T_DIR}, 15, 1000, false},
    {"aff", 1, {T_REG}, 16, 2, true},
    {0, 0, {0}, 0, 0, false}
};
