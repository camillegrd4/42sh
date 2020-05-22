/*
** EPITECH PROJECT, 2020
** echo
** File description:
** echo
*/

#include "my.h"

int check_cot(char *str, int i)
{
    int value = (my_strlen(str));

    if (str[i] == '"' && str[value - 1] == '"') {
        return 2;
    } else if ((str[i] == '"' && str[value - 1] != '"')
    || (str[i] != '"' && str[value - 1] == '"')) {
        my_putstr("Unmatched '\"'.\n");
        return 1;
    }
    return 0;
}

int print_arg(shell_t *shell)
{
    int i = 1;
    int j = 0;

    while (shell->array[i]) {
        while (shell->array[i][j] != '\0' && shell->array[i][j] != '\n') {
            if (shell->array[i][j] != '"' && shell->array[i][j] != '\\') {
                my_putchar(shell->array[i][j]);
            }
            j++;
        }
        i++;
        j = 0;
    }
    my_putchar('\n');
    return 0;
}

int calc_len_arg(char **arg)
{
    int i = 1;
    int j = 0;
    int value = 0;

    while (arg[i] != NULL) {
        j = 0;
        while (arg[i][j] != '\0') {
            value++;
            j++;
        }
        i++;
    }
    return value;
}

char *recover_arg(char **arg)
{
    int i = 1;
    int j = 0;
    int x = 0;
    int value = 0;
    char *str = malloc(sizeof(char) * (calc_len_arg(arg) + 3));
    while (arg[i]) {
        j = 0;
        if (value != 0) {
            str[x] = ' ';
            x++;
        }
        while (arg[i][j] != '\0') {
            str[x] = arg[i][j];
            x++;
            j++;
        }
        value++;
        i++;
    }
    str[x] = '\0';
    return str;
}