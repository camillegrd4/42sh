/*
** EPITECH PROJECT, 2019
** my_strncmp.c
** File description:
** my_strncmp.c
*/

#include "my.h"

int my_strncmp_to_get_line(char *s1, char *s2, int n)
{
    int i = 0;

    while (s1[i] == s2[i] && s1[i] && s2[i] && i != n) {
        i += 1;
    }
    if (i != n && s1[i] != s2[i])
        return -1;
    else
        return 0;
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    int j = 0;

    if (!s1 || !s2)
        return 84;
    while (s1[i] != '\0' && s2[j] != '\0' && i < n) {
        if (s1[i] - s2[j] < 0)
            return (s1[i] - s2[j]);
        if (s1[i] - s2[j] > 0)
            return (s1[i] - s2[j]);
        i = i + 1;
        j = j + 1;
    }
    if (s1[i] != s2[j])
        return 1;
    return 0;
}
