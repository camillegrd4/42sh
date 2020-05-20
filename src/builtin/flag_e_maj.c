/*
** EPITECH PROJECT, 2020
** e
** File description:
** e
*/

#include "my.h"

int check_cot_e_maj(char *str, int i)
{
    int value = (my_strlen(str));

    while (str[i] != 'E')
        i++;
    i++;
    if (str[i] == ' ')
        i++;
    if (str[i] == '"' && str[value - 1] == '"') {
        return 2;
    } else if ((str[i] == '"' && str[value - 1] != '"')
    || (str[i] != '"' && str[value - 1] == '"')) {
        my_putstr("Unmatched '\"'.\n");
        return 1;
    }
    return 0;
}

int flags_e_maj(shell_t *shell)
{
    int i = 2;
    int j = 0;
    int x = 0;

    if (shell->echo_path[j] == ' ')
        j++;
    if ((x = check_cot_e_maj(shell->echo_path, j)) == 2) {
        print_e_flags(shell, j);
    }
    return 0;
}