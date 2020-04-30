/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** clean string
*/

#include "my.h"

char **clean_string(char **tab)
{
    int index = 0;
    int j = 0;
    int third = 0;
    char **new = malloc(sizeof(char *) * tab_len(tab) + 1);

    if (!tab || ! new) return NULL;
    while (tab[index]) {
        j = 0;
        third = 0;
        new[index] = malloc(sizeof(char) * my_strlen(tab[index]) + 1);
        if (!new[index]) return NULL;
        while (tab[index][j]) {
            if ((j == 0 || j == my_strlen(tab[index]) - 1) &&
            tab[index][j] == ' ')
                j++;
            else new[index][third++] = tab[index][j++];
        }
        new[index++][third] = '\0';
    }
    new[index] = NULL;
    return new;
}