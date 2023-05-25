/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** address
*/

#include "common/includes/arena/defs.h"

short arena_get_real_addr(int addr)
{
    short diff = addr % MEM_SIZE;

    return (diff >= 0 ? diff : (MEM_SIZE + diff));
}
