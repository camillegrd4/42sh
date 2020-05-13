/*
** EPITECH PROJECT, 2020
** recode_function
** File description:
** recode_function
*/

#include "my.h"

const recode_t tab[] = {
    { "echo", &echo_builtin },
    { "setenv", &setting_env },
    { "env", &print_env},
    { "cd", &cd_function},
    { "exit", &exit_function},
    {"unsetenv", &unsetenv_function},
    {"NULL"},
};

builtin_t find(char *key, shell_t *shell)
{
    int i = 0;

    while (&tab[i] != NULL) {
        if (my_strcmp(tab[i].key, key) == 0) {
            return (tab[i].builtin);
        }
        if (tab[i].key == "NULL")
            return 0;
        i++;
    }
    return NULL;
}

int call_builtin(char **envp, shell_t *shell)
{
    builtin_t builtin = find(shell->array[0], shell);

    if (!(builtin))
        return 0;
    else {
        if (builtin(envp, shell) == 1)
            return 1;
        return 2;
    }
    return 0;
}