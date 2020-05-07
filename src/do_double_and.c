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
    int test = 0;

    if (is_double_and(line) == 0)
        return 0;
    separ = str_to_wordtab(line, "&");
    separ = clean_string(separ);
    while (separ[i]) {
        if ((test = check_getline(shell, envp, 0, separ[i])) != 0)
            return 2;
        printf("test >>>> %d\n", test);
        i++;
    }
    return 0;
}