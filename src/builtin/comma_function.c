/*
** EPITECH PROJECT, 2020
** comma
** File description:
** comma
*/

#include "my.h"

int call_exec_comma_function(char **envp, char *line, shell_t *shell, int x)
{
    x = call_rafters(line, envp, shell, x);
    shell->cmd = line;
    shell->array = my_str_to_world_array_pipe(shell->cmd);
    if (x == 0) {
        if (x = my_function(shell, envp) == 1) {
            return 1;
        }
    }
    return 0;
}