/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** parsing
*/

#pragma once

#include <stdbool.h>

/**
* @brief Parse the champion given in parameter.
* @param argv Argument of programme
* @param argv Number of argument in programme
* @return The struct initied, NULL if error
*/
char *strconcat(char *dest, char *src);

/**
* @brief Remove comment in the line
* @param input_user Line to filter
* @return sentence whitout comment
*/
char *filter_comment(char *input_user);

/**
* @brief Check if the line in parameter is a comment
* @param input_user Line to check
* @return true if the line is a comment or false
*/
bool is_comment(char *input_user);

/**
* @brief Separate the sentence by charactere.
* @param str The sentence to separate
* @param separate Delimiter for separate
* @return Tab of word separate pas delimiter
*/
char **str_to_word_array(char const *str, char *separate);
