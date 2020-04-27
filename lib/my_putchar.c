/*
** EPITECH PROJECT, 2019
** my_putchar.c
** File description:
** my_putchar.c
*/

#include "my.h"

int my_putchar(char c)
{
    if (write (1, &c, 1) == -1)
        return 84;
    return 0;
}