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

Test(champion_functions, new_champion)
{
    champion_t *champion = champion_new();

    cr_assert_not_null(champion);
    cr_assert_null(champion->body);
    cr_assert_null(champion->header);
}

Test(champion_functions, free_champion)
{
    champion_t *champion = champion_new();

    champion_free(champion);
}

Test(champion_functions, append_champion)
{
    champion_t *champion = champion_new();
    cmd_t *cmd = cmd_new();

    champion->body = list_new();
    cr_assert(champion_append_cmd(champion, cmd) == true);
    champion_free(champion);
}

Test(champion_functions, append_malloc_failed_champion)
{
    champion_t *champion = champion_new();
    cmd_t *cmd = cmd_new();

    champion->body = list_new();
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_FAIL);
    cr_assert(champion_append_cmd(champion, cmd) == false);
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_NORMAL);
    champion_free(champion);
}

Test(champion_functions, append_null_list_champion)
{
    champion_t *champion = champion_new();
    cmd_t *cmd = cmd_new();

    cr_assert(champion_append_cmd(champion, cmd) == false);
    champion_free(champion);
    cmd_free(cmd);
}

Test(champion_functions, append_null_cmd_champion)
{
    champion_t *champion = champion_new();
    cmd_t *cmd = NULL;

    cr_assert(champion_append_cmd(champion, cmd) == false);
    champion_free(champion);
}

Test(champion_functions, append_null_champion)
{
    champion_t *champion = NULL;
    cmd_t *cmd = cmd_new();

    cr_assert(champion_append_cmd(champion, cmd) == false);
    champion_free(champion);
    cmd_free(cmd);
}

Test(champion_functions, malloc_failed_champion)
{
    champion_t *champion = NULL;

    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_FAIL);
    champion = champion_new();
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_NORMAL);
    cr_assert_null(champion);
}

Test(champion_functions, free_null)
{
    champion_free(NULL);
}

Test(champion_fighter_functions, new_champion_fighter)
{
    champion_fighter_t *champion_fighter = champion_fighter_new();

    cr_assert_not_null(champion_fighter);
    cr_assert_null(champion_fighter->header);
    cr_assert(champion_fighter->cooldown == 0);
    cr_assert(champion_fighter->pc == 0);
    cr_assert(champion_fighter->live == false);
    champion_fighter_free(champion_fighter);
}

Test(champion_fighter_functions, free_champion_fighter)
{
    champion_fighter_t *champion_fighter = champion_fighter_new();

    champion_fighter_free(champion_fighter);
}

Test(champion_fighter_functions, malloc_failed_champion_fighter)
{
    champion_fighter_t *champion_fighter = NULL;

    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_FAIL);
    champion_fighter = champion_fighter_new();
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_NORMAL);
    cr_assert_null(champion_fighter);
}

Test(champion_fighter_functions, free_null)
{
    champion_fighter_free(NULL);
}
