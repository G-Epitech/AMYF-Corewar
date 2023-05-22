/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** defs
*/

#pragma once

#define HEADER_NAME_SIZE 128
#define HEADER_COMMENT_SIZE 2048
#define HEADER_PADDING 0
#define HEADER_PADDING_SIZE sizeof(int)
#define HEADER_MAGIC_CODE 0xea83f3

// Represent the header of a champion.
typedef struct s_header {
    char name[HEADER_NAME_SIZE + 1];        // Name of the champion
    char comment[HEADER_COMMENT_SIZE + 1];  // Comment of the champion
    unsigned int body_size;                 // N bytes in the body
} header_t;
