/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** asprintf2
*/

#pragma once

#include <unistd.h>

/**
 * @brief Like printf function but store result in given strp.
 * @param strp String in which store result
 * @param format String to format
 * @param ... Parameters to replace in format
 * @return Size of strp or -1 on fail
 */
ssize_t asprintf2(char **strp, const char *format, ...);
