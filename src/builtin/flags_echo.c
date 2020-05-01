/*
** EPITECH PROJECT, 2020
** flags
** File description:
** flags
*/

#include "my.h"

int flags_n(shell_t *shell)
{
    int i = 2;
    int j = 0;

    while (shell->array[i]) {
        while (shell->array[i][j] != '\0') {
            if (shell->array[i][j] == '"' || shell->array[i][j] == '\\') {
                j++;
            }
            my_putchar(shell->array[i][j]);
            j++;
        }
        if (shell->array[i][j] != '\0')
            my_putchar(' ');
        j = 0;
        i++;
    }
    return 0;
}

int flags_e(shell_t *shell)
{
    int i = 2;
    int j = 0;

    while (shell->array[i]) {
        while (shell->array[i][j] != '\0') {
            if (shell->array[i][j] == '"')
                j++;
            if (shell->array[i][j] == '\\' && shell->array[i][j + 1] == 'n') {
                my_putchar('\n');
                j += 2;
            }
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