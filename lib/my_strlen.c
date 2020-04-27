/*
** EPITECH PROJECT, 2019
** my_strlan.c
** File description:
** my_strlen.c
*/

#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;

    if (!str)
        return 84;
    while (str[i] != '\0' && str[i] != '\n') {
        i++;
    }
    return i;
}

int my_strlen_pipe(char const *str)
{
    int i = 0;

    if (!str)
        return 84;
    while (str[i] != '\0' && str[i] != '\n' && str[i] != '|') {
        i++;
    }
    return i;
}

int my_strlen_comma(char const *str)
{
    int i = 0;

    if (!str)
        return 84;
    while (str[i] != '\0' && str[i] != '\n' && str[i] != ';') {
        i++;
    }
    return i;
}

int my_strlen_egale(char const *str)
{
    int i = 0;

    if (!str)
        return 84;
    while (str[i] != '=') {
        i++;
    }
    return i;
}

int my_strlen_env(char *str)
{
    int i = 0;

    if (!str)
        return 84;
    while (str[i] != '\n' && str[i] != '\0') {
        i++;
    }
    return i;
}