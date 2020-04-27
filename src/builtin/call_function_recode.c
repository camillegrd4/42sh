/*
** EPITECH PROJECT, 2020
** recode_function
** File description:
** recode_function
*/

#include "my.h"

int call_function_recode_next(char **envp, shell_t *shell)
{
    if (!shell)
        return 84;
    if (my_strncmp(shell->array[0], "setenv", 6) == 0) {
        if (setenv_function(envp, shell) == 1)
            return 1;
    }
    if (my_strncmp(shell->array[0], "unsetenv", 8) == 0) {
        if (unsetenv_function(shell) == 1)
            return 1;
    }
    if (my_strncmp(shell->array[0], "env", 3) == 0) {
        print_env(shell->save_env, shell);
        return 1;
    }
    return 0;
}

int call_function_recode(char **envp, shell_t *shell)
{
    if (!shell || !envp)
        return 84;
    if (my_strncmp(shell->array[0], "cd", 2) == 0) {
        if (cd_function(shell) == 1)
            return 1;
    }
    if (my_strncmp(shell->array[0], "exit", 4) == 0) {
        if (exit_function(shell) == 1)
            return 1;
    }
    if (call_function_recode_next(envp, shell) == 1)
        return 1;
    return 0;
}