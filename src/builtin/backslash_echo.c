/*
** EPITECH PROJECT, 2020
** flags
** File description:
** flags
*/

#include "my.h"

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
    int i = 0;
    int j = 0;
    shell->echo_path = without_caract(shell->echo_path);
    shell->value = 1;
    return 0;
}