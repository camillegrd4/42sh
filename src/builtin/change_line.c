/*
** EPITECH PROJECT, 2020
** line
** File description:
** line
*/

#include "my.h"

int change_env_next(shell_t *shell, int line, char **envp)
{
    int i = 0;
    int j = 0;
    int y = 0;

    shell->name = my_strdup(shell->array[1]);
    while (envp[y] != NULL) {
        if (envp[y][i] == shell->name[j]) {
            if (find_line(envp, shell, j, y) == 1)
                y++;
            else {
                shell->line = 1;
                shell->save_env[y] = change_line(shell, envp, i, y);
                break;
            }
        } else
            y++;
    }
    return 0;
}

int check_too_much_arg(shell_t *shell)
{
    if (!shell)
        return 84;
    if (my_strncmp(shell->array[2], " ", 1) != 0 && shell->array[3]) {
        my_putstr("setenv: Too many arguments.");
        my_putchar('\n');
        return 1;
    }
    return 0;
}

int check_arg(char *name, shell_t *shell)
{
    int i = 0;

    if (!name || !shell) return 84;
    while (name[i] != '\0') {
        if (name[i] == '=') {
            my_putstr(shell->array[0]);
            my_putstr(": Variable name must contain alphanumeric characters.");
            my_putchar('\n');
            return 1;
        }
        i++;
    }
    if (check_too_much_arg(shell) == 1)
        return 1;
    return 0;
}

int change_env(char **envp, shell_t *shell)
{
    int line = 0;
    char **str = NULL;

    if (!shell->array[2])
        shell->array[2] = " ";
    if (check_arg(shell->array[1], shell) == 1)
        return 1;
    shell->line = 0;
    change_env_next(shell, line, envp);
    if (shell->line == 0) {
        shell->save_env = add_line(envp, shell);
    }
    return 0;
}

char *change_line(shell_t *shell, char **envp, int i, int y)
{
    int j = 0;
    int x = 0;
    char *new = NULL;
    shell->remove = my_strdup(shell->array[2]);
    new = malloc(sizeof(char) * (my_strlen(shell->remove)
        + my_strlen(shell->array[1]) + 2));
    while (envp[y][i] != '=') {
        new[x] = envp[y][i];
        i++;
        x++;
    }
    shell->pos = y;
    new[x] = '=';
    x++;
    while (shell->remove[j] != '\0') {
        new[x] = shell->remove[j];
        x++;
        j++;
    }
    new[x] = '\0';
    return new;
}