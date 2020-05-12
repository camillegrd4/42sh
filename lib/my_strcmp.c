/*
** EPITECH PROJECT, 2019
** my_strcmp.c
** File description:
** reproduce the behavior of the strcmp function
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    if (!s1 || !s2)
        return 84;
    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]) {
        i++;
    }
    return (s1[i] - s2[i]);
}
