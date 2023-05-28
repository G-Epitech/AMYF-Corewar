/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** position
*/

#include <stdio.h>
#include "arena/arena.h"
#include "utils/utils.h"
#include "my/includes/my.h"
#include "common/includes/champion/champion.h"

static void write_body(arena_t *arena, utils_fighter_t *utils, int position)
{
    while (position >= MEM_SIZE)
        position -= MEM_SIZE;
    for (unsigned int i = 0; i < utils->body_size; i++)
        arena->array[arena_get_real_addr(i + position)] = utils->body[i];
}

static int get_nb_pos(arena_t *arena, utils_fighter_t *utils[4], int array[4])
{
    node_t *tmp = arena->champions->first;
    champion_fighter_t *champion = NULL;
    int index = 0;
    int nb = 0;

    while (index < 4 && tmp) {
        if (utils[index]->load_address != -1) {
            champion = NODE_DATA_TO_PTR(tmp->data, champion_fighter_t *);
            champion->pc = utils[index]->load_address;
            write_body(arena, utils[index], utils[index]->load_address);
            array[nb] = utils[index]->load_address;
            nb += 1;
        }
        tmp = tmp->next;
        index += 1;
    }
    return nb;
}

static void write_pos(arena_t *arena, utils_fighter_t *utils[4], node_t *node,
int array[4])
{
    int position = 0;

    position = (array[0] * (MEM_SIZE / array[3])) + array[2];
    NODE_DATA_TO_PTR(node->data, champion_fighter_t *)->pc = position;
    write_body(arena, utils[array[1]], position);
    array[0] += 1;
    array[1] += 1;
}

static void write_all(arena_t *arena, utils_fighter_t *utils[4],
int number_champions, int array[4])
{
    node_t *node = arena->champions->first;
    int ind_array[4];

    my_memset(ind_array, 0, sizeof(int) * 4);
    ind_array[3] = number_champions;
    while (ind_array[0] < number_champions && node) {
        if (!utils[ind_array[1]]->file) {
            ind_array[1] += 1;
            node = node->next;
            continue;
        }
        if (array[ind_array[0]] != 0) {
            ind_array[2] = array[ind_array[0]];
            ind_array[0] += 1;
            continue;
        }
        write_pos(arena, utils, node, ind_array);
        node = node->next;
    }
}

void arena_init_champion_position(arena_t *arena, utils_fighter_t *utils[4])
{
    int array[4];
    int number_defines = 0;
    int number_champions = arena->champions->len;

    for (int i = 0; i < 4; i++) {
        if (utils[i]->dump > -1)
            arena->dump = utils[i]->dump;
    }
    my_memset(array, 0, sizeof(int) * 4);
    number_defines = get_nb_pos(arena, utils, array);
    if (number_defines == 0 || number_defines == 1)
        return write_all(arena, utils, number_champions, array);
}
