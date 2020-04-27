/*
** EPITECH PROJECT, 2020
** comma
** File description:
** comma
*/

#include "my.h"

char *fill_first_arg_pipe(shell_t *shell, char *line)
{
    int i = 0;
    int x = 0;
    int value = my_strlen_pipe(line);

    if (value <= 0) {
        my_putstr("Invalid null command.\n");
        return NULL;
    }
    shell->comma->first_arg_pipe = malloc(sizeof(char)
    * (my_strlen_pipe(line) + 2));
    while (i != value) {
        shell->comma->first_arg_pipe[x] = line[i];
        i++;
        x++;
    }
    shell->comma->first_arg_pipe[x] = '\0';
    return 0;
}

char *fill_second_arg_pipe(shell_t *shell, int i, char *line)
{
    int x = 0;

    if (!shell || !line)
        return NULL;
    while (line[i] == ' ' || line[i] == '|') {
        i++;
    }
    shell->comma->second_arg_pipe = malloc(sizeof(char)
    * (my_strlen(line) + 2));
    while (i < my_strlen(line) + 1) {
        shell->comma->second_arg_pipe[x] = line[i];
        i++;
        x++;
    }
    shell->comma->second_arg_pipe[x] = '\0';
    return 0;
}

int check_pipe_function(char **envp, char *line, shell_t *shell, int i)
{
    if (!envp || !line || !shell)
        return 84;
    while (line[i] != '\0') {
        if (line[i] == '|') {
            fill_first_arg_pipe(shell, line);
            fill_second_arg_pipe(shell, i, line);
            exec_first_arg(envp, line, shell, i);
            return 2;
        }
        i++;
    }
    return 0;
}

int check_comma_function(char *line, shell_t *shell, char **envp, int x)
{
    if (!line || !shell || !envp)
        return 84;
    if (call_exec_comma_function(line, shell, envp) != 1
    && (my_strncmp(line, "\n", 1) != 0)) {
        if (check_getline(shell, envp, x, line) == 84)
            return 84;
    }
    return 0;
}