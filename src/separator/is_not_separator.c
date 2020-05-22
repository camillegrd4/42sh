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

int is_pipe(char current, char plus_one, char minus_one)
{
    if (current == '|' && (plus_one == '|' || minus_one == '|'))
        return 1;
    return 0;
}

char *which_sep(char current, char plus_one, char minus_one)
{
    if (current == ';')
        return ";";
    if (current == '|' && (plus_one == '|' || minus_one == '|'))
        return "||";
    if (current == '&' && (plus_one == '&' || minus_one == '&'))
        return "&&";
    return ";";
}