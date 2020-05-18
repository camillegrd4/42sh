/*
** EPITECH PROJECT, 2020
** redirections
** File description:
** redirections
*/

#include "my.h"

int redirections_function(char **envp, char *line, shell_t *shell, int x)
{
    printf("%s\n", shell->cmd);
    mkdir(shell->array[2], S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
}