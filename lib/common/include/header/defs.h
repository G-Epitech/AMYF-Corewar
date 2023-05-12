/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** defs
*/

#pragma once

#define HEADER_NAME 128
#define HEADER_COMMENT 2048

// Represent the header of a champion.
typedef struct s_header {
    char name[HEADER_NAME];             // Name of the champion
    char comment[HEADER_COMMENT];       // Comment of the champion
} header_t;
