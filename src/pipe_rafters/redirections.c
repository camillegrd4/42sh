/*
** EPITECH PROJECT, 2020
** redirections
** File description:
** redirections
*/

#include <dirent.h>
#include "my.h"

int check_input(shell_t *shell)
{
    DIR* directory = opendir(shell->path_bis[1]);

    if (directory != NULL) {
        my_putstr(shell->path_bis[1]);
		my_putstr(": Is a directory\n");
        closedir(directory);
        return 1;
    }
    if (errno == EACCES) {
		my_putstr(shell->path_bis[1]);
        my_putstr("Permission denied\n");
        return 1;
    }
    return 0;
}

void check_deleting(shell_t *shell)
{
    struct dirent *files;
    DIR *dir;

    dir = opendir(".");
    while ((files = readdir(dir))) {
        if (strcmp(files->d_name , shell->path_bis[1]) == 0)
            remove(shell->path_bis[1]);
    }
    closedir(dir);
}

static int make_redirect(pid_t pid, shell_t *shell, char **env, int *fd)
{
    int newfd = open(shell->path_bis[1], O_CREAT | O_APPEND | O_RDWR,
                        S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
    if (!newfd)
        return 84;
    shell->array = str_to_wordtab(shell->path_bis[0], " \t");
    dup2(newfd, 1);
    close(newfd);
    if (exec_function(env, shell, pid) == 84)
        return 84;
    return 0;
}

int redirections_function(char **envp, char *line, shell_t *shell, int x)
{
    pid_t pid;
    int fd[2];

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
    } else if (pid == 0) {
        if (check_input(shell) == 1)
            return 1;
        check_deleting(shell);
        make_redirect(pid, shell, envp, fd);
    }
    _exit(EXIT_SUCCESS);
}