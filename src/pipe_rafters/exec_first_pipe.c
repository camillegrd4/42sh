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
int is_multiple_pipes(char *line)
{
    int i = 0;
    int result = 0;

    while (line[i]) {
        if (line[i] == '|')
            result += 1;
        i += 1;
    }
    if (result > 1)
        return result;
    else 
        return 0;
}

char *create_new_line_without_old_args(char **buffer)
{
    char *temp = NULL;
    int i = 1;

    while (buffer[i] && i < tab_len(buffer) + 1) {
        printf("je passe\n");
        printf("buffer[i] %s\n", buffer[i]);
        temp = strcat(buffer[i], " ");
        temp = strcat(temp, "|");
        temp = strcat(temp, " ");
        temp = strcat(temp, buffer[i + 1]);
        printf("temp %s\n", temp);
        i++;
    }
    printf("ok\n");
    return temp;
}

int exec_first_arg(char **envp, char *line, shell_t *shell, int x)
{
    pid_t pid;
    int fd[2];
    int turn = is_multiple_pipes(line) - 1;
    char *new_line = NULL;
    int i = 0;

    printf("BITE PUTAIN x %d\n", x);
    printf("turn %d\n", turn);
    shell->cmd = line;
    shell->path_bis = str_to_wordtab(line, "|");
    shell->path_bis = clean_string(shell->path_bis);

    printf("%s\n", shell->path_bis[i]);
    if ((pid = fork()) < 0) {
        my_putstr("Error fork\n");
        return 1;
    } else if (pid > 0) {
        printf("je passe\n");
        waitpid(pid, NULL, 0);
        return 2;
    }
    if (pipe(fd) == -1) {
        my_putstr("Erreur pipe\n");
        return 1;
    }
    printf("je passe ici\n");
    exec_arg(pid, shell, envp, fd);
    printf("je passe pas ici\n");
    close(fd[0]);
    exec_first_arg(envp, line, shell, x + 1);
    _exit(EXIT_SUCCESS);
}