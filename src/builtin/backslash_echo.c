/*
** EPITECH PROJECT, 2020
** flags
** File description:
** flags
*/

#include "my.h"

char *stop_caract(shell_t *shell)
{
    char *new = malloc(sizeof(char) * (my_strlen(shell->echo_path - 2) + 1));
    int i = 0;
    int j = 0;

    while (shell->echo_path[i] != '\0') {
        if (shell->echo_path[i] == '\\' && shell->echo_path[i + 1] == 'c') {
            return new;
        }
        new[j] = shell->echo_path[i];
        j++;
        i++;
    }
    new[j] = '\0';
    return new;
}

int backslash_c(shell_t *shell)
{
    shell->echo_path = stop_caract(shell);
    shell->value = 1;
    shell->without = 1;
    return 0;
}

int backslash_n(shell_t *shell)
{
    shell->value = 1;
    return 0;
}

char *without_caract(char *str)
{
    char *new = malloc(sizeof(char) * (my_strlen(str - 2) + 1));
    int i = 0;
    int j = 0;

    while (str[i] != '\0') {
        if (str[i + 1] == '\\' && str[i + 2] == 'b') {
            i += 3;
        }
        new[j] = str[i];
        j++;
        i++;
    }
    new[j] = '\0';
    return new;
}

int backslash_b(shell_t *shell)
{
    shell->echo_path = without_caract(shell->echo_path);
    shell->value = 1;
    return 0;
}