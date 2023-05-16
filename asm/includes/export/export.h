/*
** EPITECH PROJECT, 2023
** Corware
** File description:
** Exportation phase functions
*/

#pragma once

#include <stdbool.h>
#include "common/includes/champion/defs.h"

/**
 * @brief Export given champion to binary file.
 * @param filename Filename in which export given champion
 * @param champion Champion to export
 * @return Status of exporting success
 */
bool asm_export_champion(char *filename, champion_t *champion);

/**
 * @brief Create file used for exportation
 * @param filename Filename to create for exportation
 * @return File descriptor corresponding to created file or -1 on failure
 **/
int asm_export_create_file(char *filename);
