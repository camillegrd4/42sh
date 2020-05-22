/*
** EPITECH PROJECT, 2020
** fd
** File description:
** fd
*/

#include "my.h"

int pipe_loop_ext(piping_t *piping, shell_t *shell, char **envp, pid_t pid)
{
    dup2(piping->fd[0], 0);
    dup2(piping->fd[1], 1);
    if (my_function(shell, envp) == 84)
        return 84;
    exit(EXIT_FAILURE);
    return 0;
}

int set_fd(piping_t *piping)
{
    int fd[2];

    while (piping->next != NULL) {
        pipe(fd);
        piping->fd[1] = fd[1];
        piping->next->fd[0] = fd[0];
        piping = piping->next;
    }
    return 0;
}