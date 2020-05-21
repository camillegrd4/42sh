/*
** EPITECH PROJECT, 2020
** separ
** File description:
** separ
*/

#include "my.h"

int check_separ(char *line, int i, int *value)
{
    if ((line[i] == '|' && line[i + 1] != '|' && line[i - 1] != '|')
    || (line[i] == '>' && line[i + 1] == '>' && line[i - 1] != '>'
    && line[i + 2] != '>')
    || (line[i] == '>' && line[i + 1] != '>' && line[i - 1] != '>')
    || (line[i] == '<' && line[i + 1] == '<' && line[i - 1] != '<'
    && line[i + 2] != '<')
    || (line[i] == '<' && line[i + 1] != '<' && line[i - 1] != '<'))
        return 1;
    else if ((line[i] == '>' && line[i + 1] == '>' && line[i + 2] == '>')
    || (line[i] == '<' && line[i + 1] == '<' && line[i + 2] == '<')) {
        my_putstr("Missing name for redirect.");
        my_putchar('\n');
        *value = 1;
    }
    return 0;
}