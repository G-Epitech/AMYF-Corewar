/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** defs
*/

#pragma once

#include <stdbool.h>
#include "../op/defs.h"
#include "../list/defs.h"
#include "../header/defs.h"

// Represent a champion file data
typedef struct s_champion {
    header_t *header;   // Informations of the champion
    list_t *body;       // Commands list of the champion
} champion_t;

// Represent a champion fighter
typedef struct s_champion_fighter {
    header_t *header;           // Informations of the champion
    int registers[REG_NUMBER];  // All registers of the champion
    int cooldown;               // Cooldown of the champion
    bool live;                  // Check if it said “live” since the last reset
    unsigned int pc;            // Progam Counter
    int carry;                  // Success of the previous operation
} champion_fighter_t;
