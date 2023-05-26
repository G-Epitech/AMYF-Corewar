/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** champion
*/

#include <stdio.h>
#include "my/includes/my.h"
#include "execution/execution.h"
#include "operators/operators.h"
#include "common/includes/op/defs.h"
#include "common/includes/arena/defs.h"
#include "common/includes/champion/defs.h"

static void temp_execution(arena_t *arena, champion_fighter_t *champion,
parameter_t parameters[MAX_ARGS_NUMBER], char cmd)
{
    int index = (int) cmd;

    (void)arena;
    for (int i = 0; i < MAX_ARGS_NUMBER; i++)
        champion->parameters[i] = parameters[i];
    champion->cooldown = op_tab[index].nbr_cycles;
    champion->pending_cmd = index;
}

static bool get_special_case(char command,
parameter_t parameters[MAX_ARGS_NUMBER], arena_t *arena,
champion_fighter_t *champion)
{
    int index = (int) command;
    champion_fighter_t *chmp = champion;

    if (op_tab[index].nbr_args > 1)
        return false;
    if (IS_T_DIR(op_tab[index].type[0])) {
        parameters[0].type = T_DIR;
        parameters[0].value = corewar_execute_champion_read_int(arena, chmp);
    }
    if (IS_T_IND(op_tab[index].type[0])) {
        parameters[0].type = T_IND;
        parameters[0].value = corewar_execute_champion_read_short(arena, chmp);
    }
    if (IS_T_REG(op_tab[index].type[0])) {
        parameters[0].type = T_REG;
        parameters[0].value = corewar_execute_champion_read_char(arena, chmp);
    }
    temp_execution(arena, champion, parameters, command);
    return true;
}

static void get_two_bits(int array[4], unsigned char declaration,
int *index)
{
    for (int j = 1; j < 4; j++) {
        if ((declaration & j) == j) {
            array[*index] = j;
            *index -= 1;
        }
    }
}

static void get_declaration(champion_fighter_t *champion, arena_t *arena,
int array[4], parameter_t parameters[MAX_ARGS_NUMBER])
{
    char declaration = 0;
    int index = 3;
    int index1 = 0;

    declaration = corewar_execute_champion_read_char(arena, champion);
    for (int i = 0; i < 4; i++) {
        get_two_bits(array, declaration, &index);
        declaration >>= 2;
    }
    for (int i = 0; i < 4; i++) {
        if (array[i] != 0) {
            parameters[index1].type = array[i];
            index1 += 1;
        }
    }
}

void corewar_execute_champion(arena_t *arena, champion_fighter_t *champion)
{
    char cmd = corewar_execute_champion_read_char(arena, champion);
    parameter_t parameters[MAX_ARGS_NUMBER];
    int array[4];

    if (cmd < 1 || cmd >= COMMANDS_NUMBER) {
        champion->pc -= champion->readed;
        champion->readed = 0;
        return;
    }
    my_memset(parameters, 0, sizeof(parameter_t) * 4);
    my_memset(array, 0, sizeof(int) * 4);
    if (get_special_case(cmd - 1, parameters, arena, champion))
        return;
    get_declaration(champion, arena, array, parameters);
    corewar_execute_champion_read_params(arena, champion, parameters, cmd - 1);
    temp_execution(arena, champion, parameters, cmd - 1);
}
