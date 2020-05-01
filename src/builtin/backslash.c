/*
** EPITECH PROJECT, 2020
** ech
** File description:
** echo
*/

#include "my.h"

int backslash_m(shell_t *shell)
{
    shell->echo_path = remove_caract(shell->echo_path);
    shell->value = 1;
}

char *remove_caract(char *str)
{
    char *new = malloc(sizeof(char) * (my_strlen(str - 2) + 1));
    int i = 0;
    int j = 0;

    while (str[i] != '\0') {
        if (str[i] == '\\' && str[i + 1] == 'm') {
            i += 3;
        }
        new[j] = str[i];
        j++;
        i++;
    }
    new[j] = '\0';
    return new;
}