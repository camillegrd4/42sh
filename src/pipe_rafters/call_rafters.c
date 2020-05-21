/*
** EPITECH PROJECT, 2020
** call
** File description:
** call
*/

#include "my.h"

int call_rafters_next(list_t *list, int i, char *line, shell_t *shell)
{
    if ((line[i] == '>' && line[i + 1] == '>') ||
        (line[i] == '<' && line[i + 1] == '<'))
        *list = find_rafters(line[i], shell);
    else if ((line[i] == '>' && line[i + 1] != '>') ||
            (line[i] == '<' && line[i + 1] != '<'))
        *list = find_rafters2(line[i], shell);
    return 0;
}

int call_rafters(char *line, char **envp, shell_t *shell, int x)
{
    list_t list = NULL;
    int i = 0;
    int value = 0;

    while (line[i]) {
        if (line[i] == '|' && value == 0) {
            value = 1;
            return exec_first_arg(envp, line, shell, x);
        }
        if (check_separ(line, i, &value) == 1) {
            call_rafters_next(&list, i, line, shell);
            if (!(list)) return 0;
            else {
                if ((value = list(envp, line, shell, x)) == 1)
                    return 1;
            }
            value = 1;
        }
        i++;
    }
    return value;
}