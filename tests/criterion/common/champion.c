/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** champion
*/

#include <criterion/criterion.h>
#include "cmd/cmd.h"
#include "list/list.h"
#include "utils/malloc2.h"
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

Test(champion_functions, append_command) {
    champion_t *champion = champion_new();
    cmd_t *cmd = cmd_new();
    bool status = true;

    champion->body = list_new();
    status = champion_append_cmd(champion, cmd);
    cr_assert(status);
    cr_assert_eq(champion->body->len, 1);
}

Test(champion_functions, append_command_null) {
    champion_t *champion = champion_new();
    cmd_t *cmd = cmd_new();
    bool status = true;

    champion->body = list_new();
    status = champion_append_cmd(NULL, cmd);
    cr_assert(!status);
    status = champion_append_cmd(champion, NULL);
    cr_assert(!status);
    cr_assert_eq(champion->body->len, 0);
    champion->body = NULL;
    status = champion_append_cmd(champion, cmd);
    cr_assert(!status);
}

Test(champion_functions, append_command_malloc_fail) {
    champion_t *champion = champion_new();
    cmd_t *cmd = cmd_new();
    bool status = true;

    champion->body = list_new();
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_FAIL);
    status = champion_append_cmd(champion, cmd);
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_NORMAL);
    cr_assert(!status);
    cr_assert_eq(champion->body->len, 0);
}
