/*
** EPITECH PROJECT, 2020
** exec
** File description:
** exec
*/

#include "my.h"

int command_not_found(char **envp, shell_t *shell)
{
    my_putstr_without_return(shell->array[0]);
    my_putstr(": Command not found.\n");
    exit(1);
}

int access_function(int i, char **envp, char *path, shell_t *shell)
{
    errno == 0;
    if (!shell || !envp) return 84;
    if (access(path, F_OK) == 0) {
        if (execve(path, shell->array, envp) == -1) {
            if (errno == 8) {
                path = check_path(path);
                my_putstr(path);
                my_putstr(": Exec format error. Wrong Architecture.\n");
                exit(1);
            }
            else if (errno == EACCES) {
                path = check_path(path);
                my_putstr(path);
                my_putstr(": Permission denied.\n");
                exit(1);
            }
        }
        exit(1);
    }
    return 0;
}

int execve_function(char **envp, shell_t *shell)
{
    int i = 0;
    int x = 0;

    if (!envp || !shell)
        return 84;
    if ((x = exec_binary(shell, envp) != 0)
    || (x = find_path(shell, envp) != 0))
        return x;
    while (shell->path_bis[i] != NULL) {
        if (access(shell->array[0], F_OK) == 0) {
            access_function(i, envp, shell->array[0], shell);
        } else {
            exec_function_system(shell, envp, i);
        }
        i++;
    }
    command_not_found(envp, shell);
    return 0;
}

int exec_function_next(char **envp, shell_t *shell, pid_t pid)
{
    int wstatus = 0;

    if (pid == 5)
        pid = fork();
    if (pid == -1)
        return 84;
    if (pid == 0) {
        if (execve_function(envp, shell) == 1)
            exit(1);
    } else {
        pid = waitpid(pid, &wstatus, 0);
        if (check_error_father(wstatus) == 1)
            return 1;
    }
    return 0;
}

int exec_function(char **envp, shell_t *shell, pid_t pid)
{
    struct stat buf;

    if (!envp || !shell)
        return 84;
    if (my_strncmp(shell->array[0], "cd", 2) != 0
        && my_strncmp(shell->array[0], "exit", 4) != 0
        && my_strncmp(shell->array[0], "setenv", 6) != 0
        && my_strncmp(shell->array[0], "unsetenv", 8) != 0
        && my_strncmp(shell->array[0], "env", 4) != 0
        && my_strncmp(shell->array[0], "echo", 5) != 0) {
        if (exec_function_next(envp, shell, pid) == 1)
            return 1;
    }
    return 0;
}