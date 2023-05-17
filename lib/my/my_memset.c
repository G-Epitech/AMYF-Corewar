/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** my_memset
*/

#include <sys/types.h>

void *my_memset(void *pointer, unsigned char value, size_t count)
{
    unsigned char *p = (unsigned char *) pointer;

    for (size_t i = 0; i < count; i++)
        p[i] = value;
    return pointer;
}
