/*
** EPITECH PROJECT, 2020
** cd
** File description:
** cd
*/

#include "my.h"

int exit_function(char **argv, shell_t *shell)
{
    if (!shell)
        return 84;
    my_putstr("exit\n");
    exit(0);
    return 0;
}

int unsetenv_function(char **envp, shell_t *shell)
{
    if (!shell)
        return 84;
    if (my_unsetenv(shell) == 1) {
        shell->error = 1;
        return 1;
    }
    return 0;
}