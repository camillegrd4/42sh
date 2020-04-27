/*
** EPITECH PROJECT, 2020
** env
** File description:
** env
*/

#include "my.h"

int change_save_env(char **envp, shell_t *shell)
{
    int i = 0;
    int j = 0;
    char *arg_one = my_strdup(shell->array[1]);
    char *arg_two = my_strdup(shell->array[2]);

    shell->new_env = malloc(sizeof(char *)
        * (count_line(shell->save_env, shell) + 2));
    while (shell->save_env[j] != NULL) {
        shell->new_env[i] = malloc(sizeof(char)
        * (my_strlen(shell->save_env[j])
        + my_strlen(arg_one) + my_strlen(arg_two) + 2));
        shell->new_env[i] = my_strdup(shell->save_env[j]);
        j++;
        i++;
    }
    shell->new_env[i] = NULL;
    return 0;
}

char **add_line(char **envp, shell_t *shell)
{
    int i = 0;
    int j = 0;
    int y = 0;
    int x = 0;
    char *arg_one = my_strdup(shell->array[1]);
    char *arg_two = my_strdup(shell->array[2]);
    char *str = my_strcat(arg_one, arg_two);

    change_save_env(envp, shell);
    while (shell->new_env[y] != NULL) {
        y++;
    }
    shell->pos = y;
    shell->new_env[y] = my_strdup(str);
    y++;
    shell->new_env[y] = NULL;
    return shell->new_env;
}

int count(char *str)
{
    int i = 0;
    int value = 0;

    while (str[i] != '\0') {
        if (str[i] == '\n') {
            value++;
        }
        i++;
    }
    return value;
}