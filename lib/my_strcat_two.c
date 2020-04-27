/*
** EPITECH PROJECT, 2020
** my
** File description:
** my
*/

#include "my.h"

char *my_strcat_two(char *dest, char const *src)
{
    int i = 0;
    int count = 0;
    char *res = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 2));

    if (!res || !dest || !src) {
        free(res);
        return NULL;
    }
    while (dest[i]) {
        res[i] = dest[i];
        i++;
    }
    res[i] = '/';
    i++;
    while (src[count] && src[count] != '\n') {
        res[i + count] = src[count];
        count++;
    }
    res[i + count] = '\0';
    return res;
}