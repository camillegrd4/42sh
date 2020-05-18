/*
** EPITECH PROJECT, 2020
** linked list
** File description:
** kinked list
*/

#include "my.h"

const rafters_t lst[] = {
    //{ ">>", &print_env},
    //{ "<<", &cd_function},
    //{ ">", &echo_builtin },
    //{ "<", &setting_env },
    { "|", &exec_first_arg},
    {"NULL"},
};

list_t find_rafters(char str, shell_t *shell)
{
    int i = 0;
    int j = 0;

    while (&lst[i] != NULL) {
        if (my_strcmp_char(lst[i].str, str) == 0) {
            return (lst[i].list);
        }
        if (lst[i].str == "NULL")
            return 0;
        i++;
    }
    return NULL;
}

int call_rafters(char *line, char **envp, shell_t *shell, int x)
{
    list_t list = NULL;
    int i = 0;
    int value = 0;

    while (line[i]) {
        if (line[i] == '|' && line[i + 1] != '|' && line[i - 1] != '|') {
            value = 1;
            list = find_rafters(line[i], shell);
            if (!(list))
                return 0;
            else {
                if (list(envp, line, shell, x) == 1)
                    return 1;
            }
        }
        i++;
    }
    return value;
}