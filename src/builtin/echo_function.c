/*
** EPITECH PROJECT, 2020
** echo
** File description:
** echo
*/

#include "my.h"

int my_pattern(shell_t *shell, char path)
{
    stock flags[] = {
    ['n'] = flags_n(shell),
    };
    return 0;
}

int my_flags(char str)
{
    int i = 0;
    char *flags = "en";

    while (flags[i] != '\0') {
        if (str == flags[i])
            return 1;
        i = i + 1;
    }
    return 0;
}

int print_arg(shell_t *shell)
{
    int i = 1;
    int j = 0;

    while (shell->array[i]) {
        while (shell->array[i][j] != '\0') {
            if (shell->array[i][j] == '"' || shell->array[i][j] == '\\')
                j++;
            my_putchar(shell->array[i][j]);
            j++;
        }
        my_putchar(' ');
        i++;
        j = 0;
    }
    my_putchar('\n');
    return 0;
}

int echo_builtin(shell_t *shell)
{
    int i = 0;
    char letter;

    if (shell->array[1]) {
        while (shell->array[1][i] != '\0') {
            if (shell->array[1][i] == '-'
            && my_flags(shell->array[1][i + 1]) == 1) {
                my_pattern(shell, shell->array[1][i + 1]);
                return 2;
            }
            i++;
        }
    }
    print_arg(shell);
    return 0;
}