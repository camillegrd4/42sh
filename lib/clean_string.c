/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** clean string
*/

#include "my.h"

int check_space_string(int j, char **tab, int index)
{
    while (tab[index][j] == ' ' && tab[index][j + 1] == ' ')
        j++;
    if ((j == 0 || j == my_strlen(tab[index]) - 1)
        && tab[index][j] == ' ')
        j++;
    return j;
}

char **clean_string(char **tab)
{
    int index = 0;
    int j = 0;
    int third = 0;
    char **new = malloc(sizeof(char *) * (tab_len(tab) + 2));

    if (!tab || !new) return NULL;
    while (tab[index]) {
        j = 0;
        third = 0;
        new[index] = malloc(sizeof(char) * (my_strlen(tab[index]) + 2));
        if (!new[index]) return NULL;
        while (tab[index][j]) {
            j = check_space_string(j, tab, index);
            new[index][third++] = tab[index][j++];
        }
        new[index++][third] = '\0';
    }
    new[index] = NULL;
    int i = 0;
    return new;
}