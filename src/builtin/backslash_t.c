/*
** EPITECH PROJECT, 2020
** t
** File description:
** t
*/

#include "my.h"

char *add_tab(shell_t *shell)
{
    char *new = malloc(sizeof(char) * (my_strlen(shell->echo_path + 4) + 1));
    int i = 0;
    int j = 0;

    while (shell->echo_path[i] != '\0') {
        if (shell->echo_path[i] == '\\' &&
        shell->echo_path[i + 1] == 't') {
            new[j] = '\t';
            i += 2;
            j++;
        }
        new[j] = shell->echo_path[i];
        j++;
        i++;
    }
    new[j] = '\0';
    return new;
}

int backslash_t(shell_t *shell)
{
    shell->echo_path = add_tab(shell);
    shell->value = 1;
    return 0;
}