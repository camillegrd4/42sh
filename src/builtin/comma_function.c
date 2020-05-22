/*
** EPITECH PROJECT, 2020
** comma
** File description:
** comma
*/

#include "my.h"

int call_exec_comma_function(char **envp, char *line, shell_t *shell, int x)
{
    shell->cmd = clean_str(line);
    shell->array = str_to_wordtab(shell->cmd, " ");

    if (shell->array[0]) {
        x = call_rafters(line, envp, shell, x);
        if (x == 0) {
            if (x = my_function(shell, envp) == 1) {
                return 1;
            }
        }
    }
    return 0;
}