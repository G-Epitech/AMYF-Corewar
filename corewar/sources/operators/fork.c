/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** fork
*/

#include "arena/arena.h"
#include "my/includes/my.h"
#include "operators/defs.h"
#include "common/includes/node/node.h"
#include "common/includes/list/list.h"
#include "common/includes/arena/arena.h"
#include "common/includes/header/header.h"
#include "common/includes/champion/champion.h"

static void dup_registers(int registers[16], champion_fighter_t *new)
{
    for (size_t i = 0; i < 16; i++)
        new->registers[i] = registers[i];
}

bool corewar_operators_fork(arena_t *arena, champion_fighter_t *champion,
parameter_t params[MAX_ARGS_NUMBER])
{
    champion_fighter_t *new = champion_fighter_new();

    new->pc = (unsigned int) (champion->pc + params[0].value % IDX_MOD) - 1;
    new->carry = champion->carry;
    new->cooldown = new->cooldown;
    dup_registers(champion->registers, new);
    new->header = header_new();
    my_strcpy(new->header->name, champion->header->name);
    my_strcpy(new->header->comment, champion->header->comment);
    new->header->body_size = champion->header->body_size;
    list_append(arena->champions, node_new(NODE_DATA_FROM_PTR(new)));
    return true;
}
