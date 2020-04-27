/*
** EPITECH PROJECT, 2020
** env
** File description:
** env
*/

#include "my.h"

int find_line(shell_t *shell, int i, int j, int y)
{
    while (shell->name[j] != '\0') {
        if (shell->save_env[y][i] != shell->name[j]) {
            return 1;
        }
        j++;
        i++;
    }
    return 0;
}

int count_line(char **envp, shell_t *shell)
{
    int i = 0;
    int const number = 0;

    if (number > 0)
        envp = shell->save_env;
    while (envp[i] != NULL) {
        i++;
    }
    return i;
}

char **create_list_env(char **envp, shell_t *shell)
{
    int i = 0;
    int j = 0;

    shell->save_env = malloc(sizeof(char*) * (count_line(envp, shell) + 1));
    while (envp[j] != NULL) {
        shell->save_env[i] = malloc(sizeof(char) * (my_strlen(envp[j]) + 1));
        shell->save_env[i] = my_strdup(envp[j]);
        j++;
        i++;
    }
    shell->save_env[i] = NULL;
}

int print_env(char **str, shell_t *shell)
{
    int i = 0;

    while (shell->save_env[i] != NULL) {
        my_putstr(shell->save_env[i]);
        my_putchar('\n');
        i++;
    }
    return 0;
}