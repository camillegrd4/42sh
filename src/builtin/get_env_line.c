/*
** EPITECH PROJECT, 2020
** get
** File description:
** get
*/

#include "my.h"

int find_line_to_get(char *line, char **env)
{
    int i = 0;
    int result = -1;

    if (!line)
        return -1;
    while (env[i]) {
        if (my_strncmp_to_get_line(line, env[i], my_strlen(line)) == 0)
            result = i;
        i++;
    }
    return result;
}

char *get_env_line(char *line, char **env)
{
    int i = 0;
    int pos_path = find_line_to_get(line, env);
    char *result = malloc(sizeof(char) * (my_strlen(env[pos_path]) + 1));

    while (env[pos_path][i]) {
        result[i] = env[pos_path][i];
        i += 1;
    }
    result[i] = '\0';
    return result;
}