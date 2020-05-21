/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** double rafters
*/

#include "my.h"

static int make_redirect(pid_t pid, shell_t *shell, char **env)
{
    int newfd = open(shell->path_bis[1], O_APPEND | O_RDWR| O_CREAT,
                    S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);

    if (!newfd)
        return 84;
    if (pid == 0) {
        shell->array = str_to_wordtab(shell->path_bis[0], " \t");
        dup2(newfd, 1);
        close(newfd);
        if (call_builtin(env, shell) == 1)
            return 1;
        if (exec_function(env, shell, pid) == 84)
            return 84;
    }
    return 0;
}

int double_rafter(char **envp, char *line, shell_t *shell, int x)
{
    pid_t pid;
    int i = 0;

    shell->cmd = line;
    shell->path_bis = str_to_wordtab(line, ">");
    shell->path_bis = clean_string(shell->path_bis);
    if (my_strcmp(shell->path_bis[0], ">>") == 0) {
        my_putstr("Invalid null command.\n");
        return 84;
    }
    if ((pid = fork()) < 0) {
        my_putstr("Error fork\n");
        return 1;
    } else if (pid > 0) {
        waitpid(pid, NULL, 0);
        return 2;
    }
    if (check_input(shell) == 1)
        return 1;
    make_redirect(pid, shell, envp);
    _exit(EXIT_SUCCESS);
}