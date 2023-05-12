/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** header
*/

#pragma once

#include "defs.h"

/**
* @brief Create a new empty Header for a Champion.
*/
header_t *header_new(void);

/**
* @brief Free the given header Champion.
* @param champions Header to free
*/
void header_free(header_t *header);
