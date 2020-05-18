/*
** EPITECH PROJECT, 2020
** 42sh$
** File description:
** is not separator
*/

#include "my.h"

int is_not_separator(char current, char plus_one, char minus_one)
{
    if (current == ';' ||
        (current == '|' && (plus_one == '|' || minus_one == '|')) ||
        (current == '&' && (plus_one == '&' || minus_one == '&')))
        return 0;
    return 1;
}