/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** unsetenv.c
*/

#include "my.h"
#include <stdlib.h>

int strlen_equal(char *str)
{
    int i = 0;

    if (!str)
        return 84;
    while (str[i] != '=' && str[i] != '\0')
        i++;
    return i;
}

int strcmp_unset(char *check, char *arg)
{
    int i = 0;
    char *without_equal = NULL;

    if (!check || !arg)
        return 84;
    without_equal = malloc(sizeof(char) * (strlen_equal(check) + 1));
    while (check[i] != '=') {
        without_equal[i] = check[i];
        i++;
    }
    without_equal[i] = '\0';
    return (my_strcmp(without_equal, arg));
}

int size_tab(char **env)
{
    int i = 0;

    while (env[i]) {
        i++;
    }
    return i;
}

char **unsetnew_env(shell_t *shell)
{
    int i = 0;
    int j = 0;
    int x = 1;
    int find_it = 0;
    char **new_env = malloc(sizeof(char *) * (size_tab(shell->save_env) + 2));

    while (shell->save_env[i]) {
        if (strcmp_unset(shell->save_env[i], shell->array[x]) == 0) {
            find_it = 1;
            i++;
        } else {
            new_env[j++] = my_strdup(shell->save_env[i++]);
        }
    }
    if (find_it == 0)
        return shell->save_env;
    new_env[j] = NULL;
    return new_env;
}

int unset_env(char **envp, shell_t *shell)
{
    if (size_tab(shell->array) == 1) {
        my_putstr("unsetenv: Too few arguments.\n");
        return 1;
    } else
        shell->save_env = unsetnew_env(shell);
    return 0;
}