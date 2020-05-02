/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** do double and
*/

#include "my.h"

int is_double_and(char *line)
{
    int i = 0;

    while (line[i]) {
        if (line[i] == '&' && line[i + 1] == '&')
            return 1;
        i++;
    }
    return 0;
}

int do_double_and(char **envp, char *line, shell_t *shell, int x)
{
    char **separ = NULL;
    int i = 0;

    if (x == 2 || is_double_and(line) == 0) {
        return 0;
    }
    separ = str_to_wordtab(line, "&");
    separ = clean_string(separ);
    while (separ[i]) {
        if (shell->error == 1) {
            return 2;
        }
        if (check_getline(shell, envp, 0, separ[i]) == 84)
            return 84;
        i++;
    }
    return 2;
}