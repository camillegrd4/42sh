/*
** EPITECH PROJECT, 2020
** fd
** File description:
** fd
*/

#include "my.h"

int pipe_loop_ext(piping_t *piping, shell_t *shell, char **envp, pid_t pid)
{
    int x = 0;
    int stock_stdin = dup(0);
    int stock_stdout = dup(1);

    dup2(piping->fd[0], 0);
    dup2(piping->fd[1], 1);
    x = my_function(shell, envp);
    dup2(stock_stdin, 0);
    dup2(stock_stdout, 1);
    if (pid != -1)
        exit((x != 0) ? x : 0);
    if (x != 0)
        return x;
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