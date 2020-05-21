/*
** EPITECH PROJECT, 2020
** 42sh$
** File description:
** is not separator
*/

#include "my.h"

int is_not_next(char *line, int i)
{
    if (i == 0 && line[i] == '|' && line[i + 1] == '|')
        return 0;
    if (is_end(line[i]) && line[i] == '|' && line[i - 1] == '|')
        return 0;
    else if (line[i] == '|' && line[i + 1] == '|' && line[i - 1] == '|')
        return 0;
    return 1;
}

int is_not_separator(char *line, int i)
{
    if (line[i] == ';')
        return 0;
    if (i == 0 && line[i] == '&' && line[i + 1] == '&')
        return 0;
    if (is_end(line[i]) && line[i] == '&' && line[i - 1] == '&')
        return 0;
    else if (line[i] == '&' && line[i + 1] == '&' && line[i - 1] == '&')
        return 0;
    else
        return is_not_next(line, i);
    return 1;
}

int is_pipe(char current, char plus_one, char minus_one)
{
    if (current == '|' && (plus_one == '|' || minus_one == '|'))
        return 1;
    return 0;
}