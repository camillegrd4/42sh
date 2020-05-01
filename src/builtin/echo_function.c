/*
** EPITECH PROJECT, 2020
** echo
** File description:
** echo
*/

#include "my.h"

int my_pattern(shell_t *shell, char path)
{
    flags flag_checker[] = {
    ['b'] = backslash_b,
    ['n'] = backslash_n,
    ['c'] = backslash_c,
    ['m'] = backslash_m,
    };
    flag_checker[path](shell);
    return 0;
}

int my_main_flags(char str)
{
    int i = 0;
    char *flags = "bncm";

    while (flags[i] != '\0') {
        if (str == flags[i])
            return 1;
        i++;
    }
    return 0;
}

int echo_builtin(shell_t *shell)
{
    int i = 0;
    char letter;
    shell->echo_path = recover_arg(shell->array);

    if (shell->echo_path) {
        while (shell->echo_path[i] != '\0') {
            if (shell->echo_path[i] == '-' && shell->echo_path[i + 1] == 'n') {
                flags_n(shell);
                return 2;
            }
            i++;
        }
    }
    print_arg(shell);
    return 0;
}