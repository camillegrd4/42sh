/*
** EPITECH PROJECT, 2020
** comma
** File description:
** comma
*/

#include "my.h"

char *fill_first_arg(shell_t *shell, char *line)
{
    int i = 0;
    int x = 0;
    int value = my_strlen_comma(line);

    shell->comma->first_arg = malloc(sizeof(my_strlen_comma(line)) + 1);
    while (i != value) {
        shell->comma->first_arg[x] = line[i];
        i++;
        x++;
    }
    shell->comma->first_arg[x] = '\0';
    return 0;
}

char *fill_second_arg(shell_t *shell, int i, char *line)
{
    int x = 0;

    while (line[i] == ' ' || line[i] == ';') {
        i++;
    }
    shell->comma->second_arg = malloc(sizeof(my_strlen(line) - i) + 1);
    while (i < my_strlen(line) + 1) {
        shell->comma->second_arg[x] = line[i];
        i++;
        x++;
    }
    shell->comma->second_arg[x] = '\0';
    return 0;
}

int call_exec_comma_function(char **envp, char *line, shell_t *shell, int x)
{
    printf("line--->%s\n", line);
    shell->cmd = line;
    shell->array = my_str_to_world_array_pipe(shell->cmd);
    if (my_function(shell, envp) == 84)
        return 84;
    return 1;
}

int check_line(char *line, shell_t *shell, int i)
{
    while (line[i] != '\0') {
        if (line[i] == ';') {
            fill_first_arg(shell, line);
            fill_second_arg(shell, i, line);
            return 2;
        }
        i++;
    }
    return 0;
}