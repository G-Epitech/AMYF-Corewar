/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** parsing
*/

#pragma once

#include <stdbool.h>
#include "common/includes/cmd/defs.h"
#include "common/includes/champion/defs.h"

/**
 * @brief Get one champion data.
 * @param file Champion file to read (only .cor)
 * @return New complete champion
 */
champion_t *parsing_champion(char *file);

/**
 * @brief Open a file in order to read it.
 * @param file File name to open
 * @return File Descriptor of the file, or -1 if error
 */
int parsing_file_open(char *file);

/**
 * @brief Get champion header informations.
 * @param fd File descriptor of the champion file
 * @return New header
 */
header_t *parsing_header(int fd);

/**
 * @brief Get Champion body informations.
 * @param champion Champion to fill
 * @param fd File descriptor of the champion file
 * @return true if everything is good, otherwise false
 */
bool parsing_body(champion_t *champion, int fd);

/**
 * @brief Get params about Champion body.
 * @param command Command to complete
 * @param main_index Main index of reading
 * @param fd File descriptor of the champion file
 */
void parsing_get_params(cmd_t *command, unsigned int *main_index, int fd);

/**
 * @brief Display a Champion.
 * @param champion Champion to display
 */
void parsing_display(champion_t *champion);

/**
 * @brief Read a long int from file.
 * @param fd File Descriptor of the file
 * @return long int readed
 */
long int parsing_read_long_int(int fd);

/**
 * @brief Read a char from file.
 * @param fd File Descriptor of the file
 * @return char readed
 */
char parsing_read_char(int fd);

/**
 * @brief Read a int from int.
 * @param fd File Descriptor of the file
 * @Unsigned int readed
 */
int parsing_read_int(int fd);

/**
 * @brief Read a char from short.
 * @param fd File Descriptor of the file
 * @return short readed
 */
short parsing_read_short(int fd);
