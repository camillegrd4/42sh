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
        if (line[i] == '&' && line[i + 1] == '&' && line[i + 2] == '&') {
            my_putstr("Invalid null command.\n");
            return 2;
        }
        if (line[i] == '&' && line[i + 1] == '&')
            return 1;
        i++;
    }
    return 0;
}

int check_and(char **separ, int i)
{
    if (separ[1] && separ[1][0] == '\n') {
        my_putstr("Invalid null command.\n");
        return 2;
    }
    if (separ[0][0] == '\0' || separ[0][0] == '\n') {
        return 1;
    }
    return i;
}

int check_time(char **envp, char *line, shell_t *shell, int x)
{
    int static value = 0;

    if (value == 0) {
        do_double_and(envp, line, shell, x);
        value = 1;
        return 0;
    }
    value = 0;
    return 0;
}

int do_double_and(char **envp, char *line, shell_t *shell, int x)
{
    char **separ = NULL;
    int i = 0;

    separ = str_to_wordtab(line, "&");
    separ = clean_string(separ);
    /*if ((i = check_and(separ, i)) == 2)
        return 1;*/
    printf("x--->%i\n", x);
    while (separ[i]) {
        if (x != 0) {
            return 0;
        } else {
            x = call_rafters(separ[i], envp, shell, x);
            if (x != 1) {
                if (check_getline(shell, envp, 0, separ[i]) == 84)
                    return 84;
            }
        }
        i++;
    }
    return 0;
}