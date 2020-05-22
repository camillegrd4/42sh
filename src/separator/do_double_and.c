/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** do double and
*/

#include "my.h"

int do_double_and(char **envp, char *line, shell_t *shell, int x)
{
    char **separ = NULL;
    int i = 0;
    int j = 0;

    separ = str_to_wordtab(line, "&");
    separ = clean_string(separ);
    while (separ[i]) {
        if (x != 0) {
            return x;
        } else {
            j = call_rafters(separ[i], envp, shell, x);
            if (x != 1 && j != 2) {
                if (check_getline(shell, envp, 0, separ[i]) == 1)
                    return 1;
            }
        }
        i++;
    }
    return 0;
}