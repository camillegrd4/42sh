/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** double rev rafters
*/

#include "my.h"

char *get_input(int *fd, shell_t *shell)
{
    char *line = NULL;
    size_t n = 0;
    FILE *file = fopen("tmp.txt", "w+");

    while (1) {
        printf(">");
        getline(&line, &n, stdin);
        if (strncmp(line, shell->path_bis[1],
            my_strlen(shell->path_bis[1])) == 0) {
            fclose(file);
            return strcat(shell->path_bis[0], " tmp.txt");
        }
        fprintf(file, "%s", line);
    }
    fclose(file);
    return NULL;
}

int make_double_raft(pid_t pid, shell_t *shell, char **env, int *fd)
{
    if (pid == 0) {
        shell->cmd = get_input(fd, shell);
        shell->array = str_to_wordtab(shell->cmd, " \t");
        if (call_builtin(env, shell) == 1)
            return 1;
        if (exec_function(env, shell, pid) == 84)
            return 84;
    }
    return 2;
}

int making_rafters(int *fd, shell_t *shell, char **envp, pid_t pid)
{
    if (pipe(fd) == -1) {
        my_putstr("Erreur pipe\n");
        return 1;
    }
    if (check_input(shell) == 1)
        return 1;
    return make_double_raft(pid, shell, envp, fd);
}

int double_rev_rafter(char **envp, char *line, shell_t *shell, int x)
{
    pid_t pid;
    int fd[2];

    shell->cmd = line;
    shell->path_bis = str_to_wordtab(line, "<");
    shell->path_bis = clean_string(shell->path_bis);
    printf("%s\n", shell->path_bis[0]);
    /*if (my_strcmp(shell->path_bis[0], "<<") == 0) {
        my_putstr("Invalid null command.\n");
        return 84;
    }*/
    if ((pid = fork()) < 0) {
        my_putstr("Error fork\n");
        return 1;
    } else if (pid > 0) {
        waitpid(pid, NULL, 0);
        return 2;
    }
    return (making_rafters(fd, shell, envp, pid));
}