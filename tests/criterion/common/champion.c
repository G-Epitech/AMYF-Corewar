/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** champion
*/

#include <criterion/criterion.h>
#include "champion/champion.h"

Test(champion_functions, new_champion) {
    champion_t *champion = champion_new();

    cr_assert_not_null(champion);
    cr_assert_null(champion->body);
    cr_assert_null(champion->header);
}

Test(champion_functions, free_champion) {
    champion_t *champion = champion_new();

    champion_free(champion);
}

Test(champion_functions, free_null) {
    champion_t *champion = champion_new();

    champion_free(NULL);
    cr_assert_not_null(champion);
}
