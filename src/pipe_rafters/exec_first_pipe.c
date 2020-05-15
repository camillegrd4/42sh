/*
** EPITECH PROJECT, 2020
** check
** File description:
** check
*/

#include "my.h"

static int exec_father(pid_t pid, shell_t *shell, char **envp, int fd[2])
{
    int y = 0;

    shell->array = my_str_to_world_array_pipe(shell->path_bis[1]);
    if (shell->array[y][y] == '\n') {
        my_putstr("Invalid null command.\n");
        return 1;
    }
    close(fd[1]);
    dup2(fd[0], 0);
    if (call_builtin(envp, shell) == 1)
        return 1;
    if (exec_function(envp, shell, pid) == 84)
        return 84;
    close(fd[0]);
    return 0;
}

static int exec_child(shell_t *shell, pid_t pid, char **envp, int *fd)
{
    shell->array = my_str_to_world_array_pipe(shell->path_bis[0]);
    close(fd[0]);
    dup2(fd[1], 1);
    if (call_builtin(envp, shell) == 1)
        return 1;
    if (exec_function(envp, shell, pid) == 84)
        return 84;
    close(fd[1]);
    return 0;
}

static int exec_arg(pid_t pid, shell_t *shell, char **envp, int *fd)
{
    pid_t pid_two;
    if ((pid_two = fork()) < 0) {
        my_putstr("Error fork\n");
        return 1;
    }
    if (pid_two == 0) {
        exec_child(shell, pid_two, envp, fd);
    } else {
        exec_father(pid, shell, envp, fd);
    }
    return 0;
}

int exec_first_arg(char **envp, char *line, shell_t *shell, int x)
{
    pid_t pid;
    int fd[2];
    char **separ = malloc(sizeof(char) * (my_strlen(line) + 1));

    shell->cmd = line;
    shell->path_bis = str_to_wordtab(line, "|");
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
    exec_arg(pid, shell, envp, fd);
    _exit(EXIT_SUCCESS);
}