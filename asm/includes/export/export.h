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
 * @param src_file Source file given by user
 * @param champion Champion to export
 * @return Status of exporting success
 */
bool asm_export_champion(char *src_file, champion_t *champion);

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

/**
 * @brief Export given command to specified file.
 * @param cmd Command to export
 * @param cmds List of all champion's commands
 * @param file File descriptor of output file
 * @return Status of exportation success
 */
bool asm_export_cmd(cmd_t *cmd, list_t *cmds, int file);

/**
 * @brief Export parameters prototype of given command.
 * @param cmd Command of which export parameters prototype
 * @param file File descriptor of output file
 * @return true if prototype has been wrote, false otherwise
 */
bool asm_export_cmd_proto(cmd_t *cmd, int file);

/**
 * @brief Export parameters of given command.
 * @param cmd Command of which export parameters
 * @param cmds List of all champion's commands
 * @param file File descriptor of output file
 */
bool asm_export_cmd_params(cmd_t *cmd, list_t *cmds, int file);

/**
 * @brief Get labeled parameter value.
 * @param param Parameter of which get value
 * @param cmd_pos Current command position
 * @param dist Variable in which store computed distance to target
 * @param cmds List of all champion commands
 * @return Status of finding success
 */
bool asm_export_get_labeled_param(parameter_t *param, unsigned int cmd_pos,
int *dist, list_t *cmds);

/**
 * @brief Get command at given index if exists in given commands.
 * @param index Index of command to get
 * @param cmds List of commands in which search
 * @return Expected command or NULL if not found
 */
cmd_t *asm_export_get_cmd_by_index(int index, list_t *cmds);

/**
 * @brief Get real type of given parameter types.
 * @param types All merged types of parameter
 * @param allowed Allowed types of parameter
 * @return Real type of given parameter types
 */
char asm_export_cmd_get_type_of_param(char types, char allowed);

/**
 * @brief Export given body of champion.
 * @param body Body to export
 * @param file File descriptor of output file
 * @return Status of body exportation success
 */
bool asm_export_champion_body(list_t *body, int file);

/**
 * @brief Get file name of output file.
 * @param src_file Source file
 * @return Final name or NULL on error
 */
char *asm_export_get_file_name(char *src_file);
