/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** Corewar / Assembler / Utils
*/

#pragma once

#include <sys/types.h>

/**
 * @brief Write given buffer as big endian.
 * @param fd File descriptor on which write
 * @param buff Buffer to write
 * @param nbytes Number of bytes to write
 * @return Wrote size
 */
ssize_t write_big_endian(int fd, const void *buff, size_t nbytes);
