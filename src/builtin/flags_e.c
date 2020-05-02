/*
** EPITECH PROJECT, 2020
** echo
** File description:
** echo
*/

#include "my.h"

int print_e_flags_without_changes(shell_t *shell)
{
    int j = 0;

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
    my_putchar('\n');
    return 0;
}

int print_e_flags_normal(shell_t *shell)
{
    int j = 0;

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
    if (shell->without != 1)
        my_putchar('\n');
    return 0;
}

int print_e_flags(shell_t *shell, int j)
{
    shell->value = 0;
    shell->without = 0;
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
    if (shell->value != 0)
        print_e_flags_normal(shell);
    else {
        print_e_flags_without_changes(shell);
    }
    return 0;
}

int check_cot_e(char *str, int i)
{
    int value = (my_strlen(str));;

    while (str[i] != 'e')
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

int flags_e(shell_t *shell)
{
    int i = 2;
    int j = 0;
    int x = 0;

    if (shell->echo_path[j] == ' ')
        j++;
    if ((x = check_cot_e(shell->echo_path, j)) == 2) {
        print_e_flags(shell, j);
    }
    return 0;
}