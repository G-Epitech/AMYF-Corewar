/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** fork
*/

#include "list/list.h"
#include "node/node.h"
#include "arena/arena.h"
#include "header/header.h"
#include "my/includes/my.h"
#include "operators/defs.h"
#include "champion/champion.h"

static bool get_val(int *value, parameter_t *param,
champion_fighter_t *champion, arena_t *arena)
{
    int pval = param->value;
    short addr = 0;

    if (IS_T_REG(param->type)) {
        pval -= 1;
        if (pval < 0 || pval >= REG_NUMBER)
            return false;
        *value = champion->registers[pval];
        return true;
    }
    if (IS_T_IND(param->type)) {
        addr = arena_get_real_addr(champion->pc + pval);
        *value = arena->array[addr];
    } else {
        *value = pval;
    }
    return true;
}

static void dup_registers(int registers[16], champion_fighter_t *new)
{
    for (size_t i = 0; i < 16; i++)
        new->registers[i] = registers[i];
}

bool corewar_operators_fork(arena_t *arena, champion_fighter_t *champion,
parameter_t params[MAX_ARGS_NUMBER])
{
    int new_pc = 0;
    champion_fighter_t *new = champion_fighter_new();

    if (!get_val(&new, &params[0], champion, arena))
        return false;
    new->pc = (unsigned int) new_pc;
    new->carry = champion->carry;
    new->cooldown = new->cooldown;
    dup_registers(champion->registers, new);
    new->header = header_new();
    my_strcpy(new->header->name, champion->header->name);
    my_strcpy(new->header->comment, champion->header->comment);
    my_strcpy(new->header->body_size, champion->header->body_size);
    list_append(arena->champions, node_new(NODE_DATA_FROM_PTR(new)));
    return true;
}
