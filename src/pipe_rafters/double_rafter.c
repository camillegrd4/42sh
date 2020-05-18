/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** double rafters
*/

#include "my.h"

static int make_redirect(pid_t pid, shell_t *shell, char **env, int *fd)
{
    FILE *newfd = fopen(shell->path_bis[1], "a+");

    if (!newfd)
        return 84;
    shell->array = my_str_to_world_array_pipe(shell->path_bis[0]);
    close(fd[0]);
    dup2(fd[1], 1);
    if (exec_function(env, shell, pid) == 84)
        return 84;
    fwrite(fd[1], sizeof(fd[1]), 1, newfd);
    close(fd[1]);
    return 0;
}

int double_rafter(char **envp, char *line, shell_t *shell, int x)
{
    pid_t pid;
    int fd[2];
    char **separ = malloc(sizeof(char) * (my_strlen(line) + 1));

    printf("coucou\n");
    shell->cmd = line;
    shell->path_bis = str_to_wordtab(line, ">");
    shell->path_bis = clean_string(shell->path_bis);
    if ((pid = fork()) < 0) {
        my_putstr("Error fork\n");
        return 1;
    } else if (pid > 0) {
        waitpid(pid, NULL, 0);
        return 2;
    }
    if (pipe(fd) == -1) {
        my_putstr("Erreur pipe\n");
        return 1;
    }
    make_redirect(pid, shell, envp, fd);
    _exit(EXIT_SUCCESS);
}