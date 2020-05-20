/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** clean str
*/

#include "my.h"

int is_space_or_tab(char curr, char plus)
{
    if ((curr == ' ' && plus == '\t') ||
        (curr == ' ' && plus == ' ') ||
        (curr == '\t' && plus == '\t') ||
        (curr == '\t' && plus == ' '))
        return 1;
    return 0;
}

int check_space_str(int j, char *tab)
{
    while (is_space_or_tab(tab[j], tab[j + 1]))
        j++;
    if ((j == 0 || j == my_strlen(tab) - 1)
        && (tab[j] == ' ' || tab[j] == '\t'))
        j++;
    return j;
}

char *clean_str(char *tab)
{
    int index = 0;
    int j = 0;
    int third = 0;
    char *new = malloc(sizeof(char) * (my_strlen(tab) + 2));

    if (!tab || !new)
        return NULL;
    while (tab[j]) {
        j = check_space_str(j, tab);
        new[index] = tab[j];
        index++;
        j++;
    }
    new[index] = '\0';
    return new;
}