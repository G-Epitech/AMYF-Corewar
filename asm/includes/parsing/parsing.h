/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** parsing
*/

#pragma once

#include "defs.h"
#include "common/include/champion/champion.h"

/**
* @brief Parse the champion given in parameter.
* @param argv Argument of programme
* @param argv Number of argument in programme
* @return The struct initied, NULL if error
*/
champion_t *parse_champion(int argc, char **argv);

/**
* @brief Parse the body of champion.
* @param input_champion input (.s) of champion
* @return Cmd of champion
*/
list_t *parsing_champion_body(char *input_champion, file_t *file);

/**
* @brief Parse the header of champion.
* @param input_champion input (.s) of champion
* @return Header of champion
*/
header_t *parsing_champion_header(char *input_champion, file_t *file);

/**
* @brief Parse the file for get information.
* @param file_path PAthe where is located the file
* @return File parsed
*/
char *parse_file(char *file_path);

/**
* @brief Create new struct for file
* @param input_file The file 
* @return The struct initied
*/
file_t *new_file(char *input_file);
