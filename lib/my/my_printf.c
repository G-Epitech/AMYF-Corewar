/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** my_printf
*/

#include <unistd.h>
#include <stdarg.h>
#include "includes/my.h"

int error_char(char c)
{
    if (c == 'c' || c == 's' || c == 'd' || c == '%' || c == 'i')
        return (0);
    else
        return (84);
}

static int disp_stdarg(const char *format, va_list list, int index)
{
    int error = 0;
    char c = 0;

    error = error_char(format[index]);
    if (error == 0) {
        if (format[index] == 'c') {
            c = va_arg(list, int);
            return write(1, &c, 1);
        }
        if (format[index] == 's')
            return my_putstr(va_arg(list, char*));
        if (format[index] == 'i' || format[index] == 'd')
            return my_put_nbr(va_arg(list, int));
        if (format[index] == '%')
            return my_putstr("%%");
    } else
        return -1;
    return -1;
}

int my_printf(const char *format, ...)
{
    int index = 0;
    int error = 0;
    int count = 0;
    va_list list;

    va_start(list, format);
    for (;index < (int)my_strlen(format); index++){
        if (format[index] == '%'){
            count += disp_stdarg(format, list, index + 1);
            index++;
        } else {
            write(1, &format[index], 1);
            count++;
        }
        if (error > count)
            return 84;
        error = count;
    }
    va_end(list);
    return count;
}
