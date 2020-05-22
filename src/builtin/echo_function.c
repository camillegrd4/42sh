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
    ['c'] = backslash_c,
    ['n'] = backslash_n,
    ['e'] = backslash_e,
    ['r'] = backslash_r,
    ['t'] = backslash_t,
    ['v'] = backslash_v_f,
    ['f'] = backslash_v_f,
    };
    flag_checker[path](shell);
    return 0;
}

int my_main_flags(char str)
{
    int i = 0;
    char *flags = "bncertvf";

    while (flags[i] != '\0') {
        if (str == flags[i])
            return 1;
        i++;
    }
    return 0;
}

int print_one_flag(shell_t *shell, int i)
{
    int j = 0;
    int x = 0;

    if ((i = check_cot(shell->echo_path, j)) == 2) {
        print_arg(shell);
        return i;
    }
    if (i == 1) return 1;
    j = 0;
    while (shell->echo_path[x]) {
        if (check_cot(shell->echo_path, j) == 2) {
            if (shell->echo_path[x] == '\\'
            && my_main_flags(shell->echo_path[x + 1]) == 1) {
                return 2;
            }
        }
        x++;
    }
    print_arg(shell);
    return 0;
}

int call_flags_echo(shell_t *shell, int i)
{
    int j = 0;

    if (shell->echo_path[i] == '-' && shell->echo_path[i + 1] == 'n') {
        flags_n(shell);
        return 2;
    }
    if (shell->echo_path[i] == '-' && shell->echo_path[i + 1] == 'e') {
        flags_e(shell);
        return 2;
    }
    if (shell->echo_path[i] == '-' && shell->echo_path[i + 1] == 'E') {
        flags_e_maj(shell);
        return 2;
    }
    return 0;
}

int echo_builtin(char **envp, shell_t *shell)
{
    int i = 0;
    char letter;
    int j = 0;
    shell->echo_path = recover_arg(shell->array);

    if (shell->echo_path) {
        while (shell->echo_path[i] != '\0') {
            if (call_flags_echo(shell, i) == 2)
                return 2;
            i++;
        }
    }
    if (print_one_flag(shell, i) == 2)
        return 2;
    return 0;
}