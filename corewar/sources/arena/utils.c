/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** utils
*/

#include <stdbool.h>
#include "utils/utils.h"
#include "arena/arena.h"
#include "my/includes/my.h"

static bool check_args(char *args)
{
    if (args[1] == 'a' && args[2] == '\0')
        return true;
    if (args[1] == 'n' && args[2] == '\0')
        return true;
    args += 1;
    if (my_strcmp(args, "dump") == 0)
        return true;
    return false;
}

static bool handle_options(int *index, char **av, utils_fighter_t *utils[4],
int main)
{
    char *str = NULL;

    if (!check_args(av[*index]))
        return false;
    str = av[*index + 1];
    if (!str)
        return false;
    if (av[*index][1] == 'a')
        utils[main]->load_address = my_getnbr(str);
    if (av[*index][1] == 'n')
        utils[main]->prog_number = my_getnbr(str);
    if (my_strcmp(av[*index], "-dump") == 0)
        utils[main]->dump = my_getnbr(str);
    while (utils[main]->load_address >= MEM_SIZE)
        utils[main]->load_address -= MEM_SIZE;
    *index += 1;
    return true;
}

static bool set_file(char *file, utils_fighter_t *utils[4], int *main)
{
    if (my_strstr(file, "42.cor"))
        return false;
    utils[*main]->file = my_strdup(file);
    *main += 1;
    return true;
}

bool arena_utils_init(int ac, char **av, utils_fighter_t *utils[4])
{
    bool success = true;
    int main = 0;

    for (int i = 0; i < 4; i++)
        utils[i] = utils_fighter_new();
    for (int i = 1; i < ac; i++) {
        if (av[i][0] == '-')
            success = handle_options(&i, av, utils, main);
        else
            success = set_file(av[i], utils, &main);
        if (!success)
            return false;
    }
    return true;
}
