/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** parsing
*/

#pragma once

#include <stdbool.h>
#include "common/include/champion/defs.h"

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
 * @brief Get Champions header informations.
 * @param champion Champions to fill
 * @param fd File descriptor of the champion file
 * @return Returns true if everything is good, otherwise false
 */
bool parsing_header(champion_t *champion, int fd);

/**
 * @brief Display a Champion.
 * @param champion Champion to display
 */
void parsing_display(champion_t *champion);

/**
 * @brief Read a long int from file.
 * @param fd File Descriptor of the file
 * @return Unsigned long int readed
 */
unsigned long int parsing_read_long_int(int fd);

/**
 * @brief Read a char from file.
 * @param fd File Descriptor of the file
 * @return Unsigned char readed
 */
unsigned char parsing_read_char(int fd);

/**
 * @brief Read a int from int.
 * @param fd File Descriptor of the file
 * @return Unsigned int readed
 */
unsigned int parsing_read_int(int fd);

/**
 * @brief Read a char from short.
 * @param fd File Descriptor of the file
 * @return Unsigned short readed
 */
unsigned short parsing_read_short(int fd);
