/*
** EPITECH PROJECT, 2020
** flags
** File description:
** flags
*/

#include "my.h"

int print_n_flags_normal(shell_t *shell, int j)
{
    while (shell->echo_path[j] != '\0') {
        if (shell->echo_path[j] == '"' || (shell->echo_path[j] == '\\' &&
        shell->echo_path[j + 1] != 't') || (shell->echo_path[j] == ' '
        && shell->echo_path[j + 1] == '\0')) {
            j++;
        }
        if (shell->echo_path[j] == '\\' && shell->echo_path[j + 1] == 't') {
            my_putchar('\t');
            j += 2;
        }
        my_putchar(shell->echo_path[j]);
        j++;
    }
    if (shell->echo_path[j] != '\0')
        my_putchar(' ');
    return 0;
}

int print_n_flags_backslash_n(shell_t *shell, int j)
{
    while (shell->echo_path[j] != '\0') {
        if (shell->echo_path[j] == '\\' && shell->echo_path[j + 1] == 'n') {
            my_putchar('\n');
            j += 2;
        }
        if (shell->echo_path[j] == '"') {
            j++;
        }
        my_putchar(shell->echo_path[j]);
        j++;
    }
    if (shell->echo_path[j] != '\0')
        my_putchar(' ');
    return 0;
}

int print_n_flags(shell_t *shell, int j)
{
    shell->value = 0;
    while (shell->echo_path[j] != '\\' && shell->echo_path[j] != '\0') {
        j++;
    }
    while (shell->echo_path[j] != '\0') {
        if (shell->echo_path[j] == '\\'
        && my_main_flags(shell->echo_path[j + 1]) == 1) {
            my_pattern(shell, shell->echo_path[j + 1]);
        }
        j++;
    }
    if (shell->value == 0) {
        j = 3;
        print_n_flags_normal(shell, j);
    } else {
        j = 3;
        print_n_flags_backslash_n(shell, j);
    }
    return 0;
}

int flags_n(shell_t *shell)
{
    int i = 2;
    int j = 0;
    int x = 0;

    while (shell->echo_path[j] != 'n')
        j++;
    j++;
    if (shell->echo_path[j] == ' ')
        j++;
    if ((x = check_cot(shell->echo_path, j)) == 2) {
        print_n_flags(shell, j);
    } else if (x != 2 && x != 1) {
        print_n_flags_normal(shell, j);
    }

    return 0;
}