/*
** EPITECH PROJECT, 2020
** separator
** File description:
** separator
*/

#include "my.h"

const separ_t map[] = {
    { "||", &do_double_or },
    { "&&", &check_time },
    { ";", &call_exec_comma_function },
    {"NULL"},
};

separator_t find_separator(char *value, shell_t *shell)
{
    int i = 0;

    while (&map[i] != NULL) {
        if (my_strcmp(map[i].value, value) == 0) {
            return (map[i].separator);
        }
        if (my_strcmp(map[i].value, "NULL") == 0)
            return 0;
        i++;
    }
    return NULL;
}

int call_separator(char **envp, shell_t *shell, char *line, int x)
{
    separator_t separator = find_separator(shell->array[0], shell);

    if (!(separator))
        return 0;
    else {
        if (separator(envp, line, shell, x) == 1)
            return 1;
        return 2;
    }
    return 0;
}