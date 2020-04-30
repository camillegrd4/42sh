/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** tab len
*/

#include "my.h"

int tab_len(char **tab)
{
    int index = 0;

    if (!tab)
        return 0;
    while (tab[index]) {
        index++;
    }
    return index;
}