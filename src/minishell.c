/*
** EPITECH PROJECT, 2020
** mini
** File description:
** mini
*/

#include "my.h"

int my_function(shell_t *shell, char **envp)
{
    pid_t pid = 5;
    int x = 0;

    if (!envp || !shell)
        return 84;
    if ((x = call_builtin(envp, shell)) != 0)
        return x;
    else if ((x = exec_function(envp, shell, pid)) != 0) {
        return x;
    }
    return 0;
}

int check_getline(shell_t *shell, char **envp, int x, char *line)
{
    if (!shell || !envp || !line)
        return 84;
    if (x != -1) {
        shell->cmd = line;
        shell->array = my_str_to_world_array(shell->cmd);
    }
    if (!shell->cmd) {
        my_putstr("exit\n");
        exit(0);
    } else if (x != -1) {
        if (my_function(shell, envp) == 1) {
            return 1;
        }
    }
    return 0;
}

int principal_function(char **envp, shell_t *shell)
{
    size_t n = 0;
    char *line = NULL;
    static int x = 0;
    static int status = 0;
    int i = 0;

    while (1) {
        i = 0;
        if (isatty(STDIN_FILENO) == 1)
            prompt_user(shell);
        x = getline(&line, &n, stdin);
        if (x == -1 && !isatty(0))
            exit(status);
        else if (x == -1 && isatty(0)) {
            free(shell);
            my_putstr("exit\n");
            exit(0);
        } else
            x = call_separator(envp, shell, line, x);
    }
    return 0;
}

char minishel(char **argv, char **envp)
{
    shell_t *shell = NULL;

    if (!argv || !envp)
        return 84;
    shell = init_struct_minishell(envp);
    create_list_env(envp, shell);
    if (!shell)
        return 84;
    if (principal_function(envp, shell) == 84) {
        free(shell);
        return 84;
    }
    return 0;
}