/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** unsetenv.c
*/

#include "my.h"
#include <stdlib.h>

int strlen_equal(char const *str)
{
    int i = 0;

    while (str[i] != '=')
        i++;
    return i;
}

int strcmp_unset(char const *check, char const *arg)
{
    int i = 0;
    char *without_equal = NULL;

    if (check == NULL)
        return 84;
    without_equal = malloc(sizeof(char) * (strlen_equal(check) + 1));
    while (check[i] != '=') {
        without_equal[i] = check[i];
        i++;
    }
    without_equal[i] = '\0';
    return (my_strcmp(without_equal, arg));
}

char **unsetnew_env(all_t *all)
{
    int i = 0;
    int j = 0;
    int find_it = 0;
    char **new_env = malloc(sizeof(char *) * (tab_size(all->envcpy)));

    while (all->envcpy[i]) {
        if (strcmp_unset(all->envcpy[i], all->rules[1]) == 0) {
            i++;
            find_it = 1;
        }
        new_env[j++] = my_strdup(all->envcpy[i++]);
    }
    if (find_it == 0)
        return all->envcpy;
    new_env[j + 1] = NULL;
    return new_env;
}

int unset_env(shell_t *shell)
{
    if (tab_size(all->rules) > 2) {
        my_putstr("unsetenv: Too few arguments.\n");
        return 1;
    }
    else
        all->envcpy = unsetnew_env(all);
    return 0;
}