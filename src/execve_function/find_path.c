/*
** EPITECH PROJECT, 2020
** path
** File description:
** path
*/

#include "my.h"

int find_path(shell_t *shell, char **envp)
{
    int i = 0;

    if (!shell || !envp)
        return 84;
    while (envp[i]) {
        if (my_strncmp_next(envp[i], "PATH", 4) == 0) {
            shell->path_bis = my_str_to_world_array_colon(&envp[i][5]);
            return 0;
        }
        i++;
    }
    return 84;
}