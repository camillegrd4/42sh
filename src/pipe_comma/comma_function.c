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

    while (line[i] == ' ' || line[i] == ';' || line[i] == '\t') {
        i++;
    }
    if (line[i] == '\0' || line[i] == '\n')
        return 0;
    shell->comma->second_arg = malloc(sizeof(my_strlen(line) - i) + 1);
    while (i < my_strlen(line) + 1) {
        shell->comma->second_arg[x] = line[i];
        i++;
        x++;
    }
    shell->comma->second_arg[x] = '\0';
    return 0;
}

int check_path_comma(int a, shell_t *shell, char **envp)
{
    if (shell->array[a] != NULL)
        if (my_function(shell, envp) == 84)
            return 84;
    return 0;
}

int call_exec_comma_function(char *line, shell_t *shell, char **envp)
{
    int i = 0;
    int y = 0;
    int x = 0;
    int a = 0;
    int value = 0;

    if (check_line(line, shell, i) == 0)
        return 0;
    while (shell->path_bis[i]) {
        if (shell->path_bis[i][y] == '\0')
            return 1;
        while (shell->path_bis[i][y] == ' ' || shell->path_bis[i][y] == ';')
            y++;
        if (shell->path_bis[i][y] != ';' && shell->path_bis[i][y] != ' ') {
            shell->array = my_str_to_world_array_pipe(shell->path_bis[i]);
            value = 1;
            if (check_path_comma(a, shell, envp) == 84) return 84;
        }
        i++;
    }
    return 1;
}

int check_line(char *line, shell_t *shell, int i)
{
    int value = 0;
    char **path = NULL;
    int j = 0;

    while (line[i] != '\0') {
        if (line[i] == ';') {
            shell->path_bis = my_str_to_world_array_comma(line);
            return 2;
        }
        i++;
    }
    return 0;
}