/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** params
*/

#include "my/includes/my.h"
#include "common/includes/op/defs.h"
#include "common/includes/arena/defs.h"
#include "common/includes/champion/defs.h"

int corewar_execute_champion_read_int(arena_t *arena, unsigned int *pos)
{
    int nb = 0;

    for (unsigned int i = *pos; i < *pos + 4; i++) {
        nb <<= 8;
        nb |= arena->array[i];
    }
    *pos += 4;
    return nb;
}

short corewar_execute_champion_read_short(arena_t *arena, unsigned int *pos)
{
    short nb = 0;

    for (unsigned int i = *pos; i < *pos + 2; i++) {
        nb <<= 8;
        nb |= arena->array[i];
    }
    *pos += 2;
    return nb;
}

char corewar_execute_champion_read_char(arena_t *arena, unsigned int *pos)
{
    char nb = 0;

    nb |= arena->array[*pos];
    *pos += 1;
    return nb;
}

static void special_case_indexes(arena_t *arena, champion_fighter_t *champion,
parameter_t *parameters, int index[2])
{
    if (!IS_T_DIR(op_tab[index[0]].type[index[1]]))
        parameters[index[1]].value =
        corewar_execute_champion_read_short(arena, &champion->pc);
    else
        parameters[index[1]].value =
        corewar_execute_champion_read_int(arena, &champion->pc);
}

void corewar_execute_champion_read_params(arena_t *arena,
champion_fighter_t *champion, parameter_t *parameters, int cmd_index)
{
    int index_array[2];
    int index = 0;

    index_array[0] = cmd_index;
    my_memset(index_array, 0, sizeof(int) * 2);
    while (parameters[index].type != 0) {
        index_array[1] = index;
        if (parameters[index].type == T_REG)
            parameters[index].value =
            corewar_execute_champion_read_char(arena, &champion->pc);
        if (parameters[index].type == T_DIR)
            special_case_indexes(arena, champion, parameters, index_array);
        if (parameters[index].type == T_IND)
            parameters[index].value =
            corewar_execute_champion_read_short(arena, &champion->pc);
        index += 1;
    }
}
