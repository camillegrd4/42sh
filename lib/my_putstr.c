/*
** EPITECH PROJECT, 2019
** my_putstr.c
** File description:
** my_putstr.c
*/

#include "my.h"

int my_putstr(char const *str)
{
    int i = 0;

    if (!str)
        return 84;
    while (str[i] != '\0') {
        if (my_putchar(str[i]) == 84)
            return 84;
        i++;
    }
    return 0;
}

int my_putstr_without_return(char const *str)
{
    int i = 0;

    if (!str)
        return 84;
    while (str[i] != '\0' && str[i] != '\n') {
        if (my_putchar(str[i]) == 84)
            return 84;
        i++;
    }
    return 0;
}
