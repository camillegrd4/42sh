/*
** EPITECH PROJECT, 2020
** or
** File description:
** or
*/

#include "my.h"

int is_double_or(char *line)
{
    int i = 0;

    while (line[i]) {
        if (line[i] == '|' && line[i + 1] == '|')
            return 1;
        i++;
    }
    return 0;
}

int do_double_or(char **envp, char *line, shell_t *shell, int x)
{
    char **separ = NULL;
    int i = 0;
    static int value = 0;

    if (x == 2 || is_double_or(line) == 0)
        return 0;
    separ = str_to_wordtab(line, "|");
    separ = clean_string(separ);
    value = 0;
    while (separ[i]) {
        if (shell->error == 0 && value == 1) {
            printf("pq\n");
            return 2;
        } else {
            if (check_getline(shell, envp, 0, separ[i]) == 84)
            return 84;
        }
        i++;
        value++;
    }
    return 2;
}