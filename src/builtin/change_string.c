/*
** EPITECH PROJECT, 2020
** change
** File description:
** change
*/

#include "my.h"

char *change_string_next(char *compare, char *line, int x, int i)
{
    while (line[i]) {
        compare[x] = line[i];
        i++;
        x++;
    }
    compare[x] = '\n';
    return compare;
}

char *change_string(char *str, char *line, int j, int i)
{
    int x = 0;
    int y = 0;
    char *compare = calloc((my_strlen(line) + calc_len(str) + 2),
        sizeof(char));

    while (y != i - 1) {
        compare[x] = line[y];
        y++;
    }
    while (str[j] != '=')
        j++;
    j++;
    while (str[j] != '\n') {
        compare[x] = str[j];
        j++;
        x++;
    }
    compare = change_string_next(compare, line, x, i);
    return compare;
}