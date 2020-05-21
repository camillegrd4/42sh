/*
** EPITECH PROJECT, 2020
** v
** File description:
** v
*/

#include "my.h"

int count_char(char *str)
{
    int i = 0;
    int count = 0;
    bool start = false;

    while (str[i] && str[i] != '\\' &&
            (str[i + 1] != 'v' || str[i + 1] != 't')) {
        if (start == true)
            count++;
        if (str[i] == '\"')
            start = true;
        i++;
    }
    return count;
}

char *add_line_vertical(shell_t *shell)
{
    int i = 0;
    int j = 0;
    int value = count_char(shell->echo_path);
    char *new = malloc(sizeof(char) *
                (my_strlen(shell->echo_path) + (value) + 1));

    while (shell->echo_path[i] != '\0') {
        if (shell->echo_path[i] == '\\' &&
        (shell->echo_path[i + 1] == 'f' || shell->echo_path[i + 1] == 'v')) {
            i += 2;
            new[j++] = '\n';
            while (value != 0) {
                new[j] = ' ';
                j++;
                value--;
            }
        }
        new[j++] = shell->echo_path[i++];
    }
    new[j] = '\0';
    return new;
}

int backslash_v_f(shell_t *shell)
{
    shell->echo_path = add_line_vertical(shell);
    shell->value = 1;
    return 0;
}