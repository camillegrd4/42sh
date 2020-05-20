/*
** EPITECH PROJECT, 2020
** redirections verse
** File description:
** versign
*/

#include <dirent.h>
#include "my.h"

static int make_reverse(pid_t pid, shell_t *shell, char **env, int *fd)
{
    int newfd = open(shell->path_bis[1], O_CREAT | O_APPEND | O_RDWR,
                        S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
    if (!newfd)
        return 84;
    shell->array = str_to_wordtab(shell->path_bis[0], " \t");
    dup2(newfd, 0);
    close(newfd);
    if (exec_function(env, shell, pid) == 84)
        return 84;
    return 1;
}

int reverse_function(char **envp, char *line, shell_t *shell, int x)
{
    pid_t pid;
    int fd[2];

    shell->cmd = line;
    shell->path_bis = str_to_wordtab(line, "<");
    shell->path_bis = clean_string(shell->path_bis);
    if ((pid = fork()) < 0) {
        my_putstr("Error fork\n");
        return 1;
    } else if (pid > 0) {
        waitpid(pid, NULL, 0);
        return 2;
    } if (pipe(fd) == -1) {
        my_putstr("Erreur pipe\n");
        return 1;
    } else if (pid == 0) {
        if (check_input(shell) == 1)
            return 1;
        make_reverse(pid, shell, envp, fd);
        return 1;
    }
}