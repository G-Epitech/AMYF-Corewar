/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** parsing
*/

#pragma once

#include <stdbool.h>

typedef struct s_file file_t;

/**
* @brief Remove comment in the line.
* @param input_user Line to filter
* @return sentence whitout comment
*/
char *parsing_filter_comment(char *input_user);

/**
* @brief Check if the line in parameter is a comment.
* @param input_user Line to check
* @return true if the line is a comment or false
*/
bool parsing_is_comment(char *input_user);

/**
* @brief Free a tab.
* @param tab Tab to free
*/
void free_str_tab(char **tab);

/**
* @brief Check if the line is empty.
* @param input_user The line to check
* @return true if line is empty else no
*/
bool parsing_is_empty(char *input_user);

/**
* @brief Check if the line is not wrong.
* @param file File structure with file and index
* @return true if line is not good else false
*/
bool parsing_wrong_line(file_t *file);
