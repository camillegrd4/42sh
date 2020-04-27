/*
** EPITECH PROJECT, 2020
** setenv function
** File description:
** setenv function
*/

#include "my.h"

int check_letter(char **envp, shell_t *shell)
{
    int i = 1;
    int j = 0;

    while (shell->array[i][j] != '\0') {
        if ((shell->array[i][j] < 'a' || shell->array[i][j] > 'z')
        && (shell->array[i][j] < 'A' || shell->array[i][j] > 'Z')
        && (shell->array[i][j] < '1' || shell->array[i][j] > '9')) {
            my_putstr("setenv: Variable name must contain ");
            my_putstr("alphanumeric characters.\n");
            return 1;
        }
        j++;
    }
    return 0;
}

int check_setenv(char **envp, shell_t *shell)
{
    if (!shell->array[1]) {
        print_env(shell->save_env, shell);
        return 2;
    }
    if ((shell->array[1][0] < 'a' || shell->array[1][0] > 'z')
    && (shell->array[1][0] < 'A' || shell->array[1][0] > 'Z')) {
        printf("setenv: Variable name must begin with a letter.\n");
        return 1;
    }
    if (check_letter(envp, shell) == 1)
        return 1;
    return 0;
}

int setenv_function(char **envp, shell_t *shell)
{
    int i = 0;
    static int x = 0;

    if (!shell)
        return 84;
    x = check_setenv(envp, shell);
    if (x == 1)
        return 1;
    if (x == 2)
        return 0;
    change_env(envp, shell);
    return 0;
}