/*
** EPITECH PROJECT, 2020
** comma
** File description:
** comma
*/

#include "my.h"

int is_double_pipe(char *line)
{
    int i = 0;

    while (line[i]) {
        if (line[i] == '|' && line[i + 1] == '|' && line[i + 2] != '|')
            return 1;
        i++;
    }
    return 0;
}

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

int check_pipe_function(char **envp, char *line, shell_t *shell, int x)
{
    int i = 0;

    if (!envp || !line || !shell)
        return 84;
    if (is_double_pipe(line) != 0)
        return 0;
    while (line[i] != '\0') {
        if (line[i] == '|') {
            fill_first_arg_pipe(shell, line);
            fill_second_arg_pipe(shell, i, line);
            exec_first_arg(envp, line, shell, i);
            return 0;
        }
        i++;
    }
    return 0;
}