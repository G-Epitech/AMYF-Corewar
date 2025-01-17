/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** init
*/

#include <unistd.h>
#include "utils/utils.h"
#include "arena/arena.h"
#include "my/includes/my.h"
#include "parsing/parsing.h"
#include "common/includes/list/list.h"
#include "common/includes/arena/arena.h"
#include "common/includes/utils/malloc2.h"
#include "common/includes/champion/champion.h"

static champion_fighter_t *new_champion(utils_fighter_t *champion_utils)
{
    champion_fighter_t *champion = champion_fighter_new();
    int fd = parsing_file_open(champion_utils->file);

    if (fd == -1)
        return NULL;
    champion->header = parsing_header(fd);
    champion->registers[0] = champion_utils->prog_number;
    champion_utils->body_size = champion->header->body_size;
    champion_utils->body =
    malloc2(sizeof(unsigned char) * champion->header->body_size);
    if (!champion_utils->body)
        return NULL;
    my_memset(champion_utils->body, '\0',
    sizeof(unsigned char) * champion->header->body_size);
    read(fd, champion_utils->body, champion->header->body_size);
    return champion;
}

static void array_remove_possibility(int array[4], int nb_to_remove)
{
    for (int i = 0; i < 4; i++) {
        if (array[i] == nb_to_remove)
            array[i] = -1;
    }
}

void set_champion_id(arena_t *arena)
{
    node_t *tmp = arena->champions->first;
    champion_fighter_t *champion = NULL;
    int array[4];
    int index = 0;

    for (int i = 0; i < 4; i++)
        array[i] = i + 1;
    while (tmp) {
        champion = NODE_DATA_TO_PTR(tmp->data, champion_fighter_t *);
        if (champion->registers[0] > 0)
            array_remove_possibility(array, champion->registers[0]);
        tmp = tmp->next;
    }
    tmp = arena->champions->first;
    while (tmp) {
        champion = NODE_DATA_TO_PTR(tmp->data, champion_fighter_t *);
        if (champion->registers[0] <= 0)
            champion->registers[0] = array[index++];
        tmp = tmp->next;
    }
}

static void free_utils(utils_fighter_t *utils[4])
{
    for (int i = 0; i < 4; i++)
        utils_fighter_free(utils[i]);
}

arena_t *arena_init(int ac, char **av)
{
    arena_t *arena = arena_new();
    champion_fighter_t *champion = NULL;
    utils_fighter_t *utils[4] = {NULL};

    if (!arena)
        return NULL;
    if (!arena_utils_init(ac, av, utils))
        return NULL;
    arena->champions = list_new();
    utils_array_sort(utils);
    for (int i = 0; i < 4; i++) {
        if (!utils[i]->file)
            continue;
        champion = new_champion(utils[i]);
        arena_append_champion(arena, champion);
    }
    set_champion_id(arena);
    arena_init_champion_position(arena, utils);
    free_utils(utils);
    return arena;
}
