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
        arena->array[i + position] = utils->body[i];
}

static int get_nb_pos(arena_t *arena, utils_fighter_t *utils[4], int array[4])
{
    node_t *tmp = arena->champions->first;
    int index = 0;
    int nb = 0;

    while (index < 4 && tmp) {
        if (utils[index]->load_address != -1) {
            write_body(arena, utils[index], utils[index]->load_address);
            array[nb] = utils[index]->load_address;
            nb += 1;
        }
        tmp = tmp->next;
        index += 1;
    }
    return nb;
}

static void write_all(arena_t *arena, utils_fighter_t *utils[4],
int number_champions, int array[4])
{
    int index_mem = 0;
    int index_utils = 0;
    int position = 0;
    int delta = 0;

    while (index_mem < number_champions) {
        if (!utils[index_utils]->file) {
            index_utils += 1;
            continue;
        }
        if (array[index_mem] != 0) {
            delta = array[index_mem];
            index_mem += 1;
            continue;
        }
        position = (index_mem * (MEM_SIZE / number_champions)) + delta;
        write_body(arena, utils[index_utils], position);
        index_mem += 1;
        index_utils += 1;
    }
}

void arena_init_champion_position(arena_t *arena, utils_fighter_t *utils[4])
{
    int array[4];
    int number_defines = 0;
    int number_champions = arena->champions->len;

    my_memset(array, 0, sizeof(int) * 4);
    number_defines = get_nb_pos(arena, utils, array);
    if (number_defines == 0 || number_defines == 1)
        return write_all(arena, utils, number_champions, array);
}
