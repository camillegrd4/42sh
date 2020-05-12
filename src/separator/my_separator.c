/*
** EPITECH PROJECT, 2020
** separator
** File description:
** separator
*/

#include "my.h"

int my_pattern_separator(char **envp, char *line, shell_t *shell, char x,
char path)
{
    flags_separator flag_checker[] = {
        [';'] = call_exec_comma_function,
        ['|'] = is_or,
        ['&'] = check_time,
    };
    flag_checker[path](envp, line, shell, x);
    return 0;
}

int my_separator_flags(char line, shell_t *shell)
{
    int i = 0;
    char *flags = {";|&"};

    while (flags[i] != '\0') {
        if (line == flags[i]) {
            shell->command_done = 1;
            return 1;
        }
    i++;
    }
    return 0;
}