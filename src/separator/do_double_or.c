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
        if (line[i] == '|' && line[i + 1] == '|' && line[i + 2] == '|') {
            my_putstr("Invalid null command.\n");
            return 2;
        }
        else if (line[i] == '|' && line[i + 1] == '|' && line[i + 2] != '|')
            return 1;
        i++;
    }
    return 0;
}

int check_or(char **separ)
{
    if (separ[0] && (separ[0][0] == '\n' || separ[0][0] == '\0'
    || !separ[0][0])) {
        my_putstr("Invalid null command.\n");
        return 2;
    }
    if (separ[1] && separ[1][0] == '\n') {
        my_putstr("Invalid null command.\n");
        return 2;
    }
    if (!separ[1]) {
        my_putstr("Invalid null command.\n");
        return 2;
    }
    return 0;
}

int do_double_or(char **envp, char *line, shell_t *shell, int x)
{
    char **separ = NULL;
    int i = 0;
    separ = str_to_wordtab(line, "|");
    separ = clean_string(separ);
    //if (check_or(separ) == 2)
        //return 2;
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