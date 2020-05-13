/*
** EPITECH PROJECT, 2020
** comma
** File description:
** comma
*/

#include "my.h"

int call_exec_comma_function(char **envp, char *line, shell_t *shell, int x)
{
    shell->cmd = line;
    shell->array = my_str_to_world_array_pipe(shell->cmd);
    if (my_function(shell, envp) == 84)
        return 84;
    return 0;
}