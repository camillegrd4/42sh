/*
** EPITECH PROJECT, 2020
** my_strdup
** File description:
** my_strdup
*/

#include "my.h"

char *my_strdup(char const *str)
{
    char *dest = NULL;
    int i = 0;

    if (!str)
        return NULL;
    dest = malloc(sizeof(char) * (my_strlen(str) + 2));
    if (!dest)
        return NULL;
    while (str[i] != 0) {
        dest[i] = str[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}