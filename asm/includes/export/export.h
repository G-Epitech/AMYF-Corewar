/*
** EPITECH PROJECT, 2023
** Corware
** File description:
** Exportation phase functions
*/

#pragma once

#include <stdbool.h>
#include "common/includes/cmd/cmd.h"
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

/**
 * @brief Export given header of champion to binary file.
 * @param header Header to export
 * @param file File descriptor of output file
 */
void asm_export_champion_header(header_t *header, int file);

/**
 * @brief Get size of parameters prototype for given command if needed.
 * @param cmd Command of which get size of parameters prototype
 * @return Size of prototype if needed, 0 otherwise
 */
int asm_export_cmd_size_get_proto(cmd_t *cmd);

/**
 * @brief Get output size of given parameter type
 * @param type Type of parameter of which get size
 * @param allowed Allowed types of the reference command
 * @return Size of parameter
 */
char asm_export_cmd_size_get_param(char type, char allowed);

/**
 * @brief Get total size of command parameters.
 * @param cmd Command of which get parameters size.
 * @return Total size of parameters
 */
int asm_export_cmd_size_get_params(cmd_t *cmd);

/**
 * @brief Evaluate the size of given command.
 * @param cmd Command to evaluate
 * @return int Final size of given command
 */
int asm_export_cmd_size_eval(cmd_t *cmd);

/**
 * @brief Prepare champion exportation.
 * @param header Header to export
 * @param commands List of commands to export
 * @return Success status
 */
bool asm_export_prepare(header_t *header, list_t *commands);
