/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** parsing
*/

#pragma once

#include "defs.h"
#include "common/includes/champion/champion.h"

#define PARSING_NAME 0
#define PARSING_COMMENT 1
#define PARSING_ERROR 2
#define PARSING_LABEL_COMPLETE 0
#define PARSING_LABEL_IMCOMPLE 1

/**
* @brief Parse the champion given in parameter.
* @param argv Argument of programme
* @param argv Number of argument in programme
* @return The struct initied, NULL if error
*/
champion_t *parsing_champion(int argc, char **argv);

/**
* @brief Parse the body of champion.
* @param input_champion input (.s) of champion
* @return Cmd of champion
*/
bool parsing_champion_body(file_t *file, champion_t *champion);

/**
* @brief Parse the header of champion.
* @param input_champion Input (.s) of champion
* @return Header of champion
*/
header_t *parsing_champion_header(file_t *file);

/**
* @brief Parse the file for get information.
* @param file_path Path where is located the file
* @return File parsed
*/
char *parsing_parse_file(char *file_path);

/**
* @brief Create new struct for file.
* @param input_file The file who describe the champion
* @return The struct initied
*/
file_t *file_new(char *input_file);

/**
* @brief Free the the file structure.
* @param file File to free
*/
void file_free(file_t *file);

/**
* @brief Create new struct for label handler.
* @return The struct initied
*/
label_handler_t *label_handler_new(void);

/**
* @brief Append a label in list
* @param list_labels List of label
* @param label Label to add in list
* @return true if no error else false
*/
bool label_append(list_t *list_labels, label_t *label);

/**
* @brief Create a new label
* @return The struct initied
*/
label_t *label_new(void);

/**
* @brief Find label in file of champion
* @param list_labels Handler of label
* @param file File where check
* @return true if no error else false
*/
bool find_label(label_handler_t *handler, file_t *file);
