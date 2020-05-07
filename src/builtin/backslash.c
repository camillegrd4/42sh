/*
** EPITECH PROJECT, 2020
** ech
** File description:
** echo
*/

#include "my.h"

char *remove_all_before(char *str)
{
    char *new = new = malloc(sizeof(char) * (3) + 1);
    int i = 0;
    int j = 0;

    while (i != 2) {
        new[j] = str[i];
        i++;
        j++;
    }
    while (str[i] != '\\' && str[i + 1] != 'r') {
            i ++;
    }
    i += 1;
    new = malloc(sizeof(char) * (my_strlen(str) + 1));
    while (str[i] != '\0') {
        new[j] = str[i];
        j++;
        i++;
    }
    new[j] = '\0';
    return new;
}

int backslash_r(shell_t *shell)
{
    shell->echo_path = remove_all_before(shell->echo_path);
    shell->value = 1;
}

char *remove_caract(char *str)
{
    char *new = malloc(sizeof(char) * (my_strlen(str - 2) + 1));
    int i = 0;
    int j = 0;

    while (str[i] != '\0') {
        if (str[i] == '\\' && str[i + 1] == 'e') {
            i += 3;
        }
        new[j] = str[i];
        j++;
        i++;
    }
    new[j] = '\0';
    return new;
}

int backslash_e(shell_t *shell)
{
    shell->echo_path = remove_caract(shell->echo_path);
    shell->value = 1;
}