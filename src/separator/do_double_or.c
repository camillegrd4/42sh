/*
** EPITECH PROJECT, 2020
** or
** File description:
** or
*/

#include "my.h"

int do_double_or(char **envp, char *line, shell_t *shell, int x)
{
    char **separ = NULL;
    int i = 0;

    separ = str_to_wordtab(line, "&");
    separ = clean_string(separ);
    while (separ[i]) {
        if (x == 0) {
            return 0;
        } else {
            x = call_rafters(line, envp, shell, x);
            if (x != 1)
                check_getline(shell, envp, 0, separ[i]);
        }
        i++;
    }
    return 2;
}