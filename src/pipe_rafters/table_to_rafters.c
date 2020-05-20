/*
** EPITECH PROJECT, 2020
** linked list
** File description:
** kinked list
*/

#include "my.h"

const rafters_t lst[] = {
    { ">>", &double_rafter },
    { "<<", &double_rev_rafter },
    { "|", &exec_first_arg },
    {"NULL"},
};

const rafters2_t lst2[] = {
    { "<", &reverse_function },
    { ">", &redirections_function },
    {"NULL"},
};

list_t find_rafters(char str, shell_t *shell)
{
    int i = 0;
    int j = 0;

    while (&lst[i] != NULL) {
        if (my_strcmp_char(lst[i].str, str) == 0)
            return (lst[i].list);
        if (lst[i].str == "NULL")
            return 0;
        i++;
    }
    return NULL;
}

list_t find_rafters2(char str, shell_t *shell)
{
    int i = 0;
    int j = 0;

    while (&lst2[i]!= NULL) {
        if (my_strcmp_char(lst2[i].str, str) == 0)
            return (lst2[i].list);
        if (lst2[i].str == "NULL")
            return 0;
        i++;
    }
    return NULL;
}

int check_separ(char *line, int i)
{
    if ((line[i] == '|' && line[i + 1] != '|' && line[i - 1] != '|')
    || (line[i] == '>' && line[i + 1] == '>' && line[i - 1] != '>'
    && line[i + 2] != '>')
    || (line[i] == '>' && line[i + 1] != '>' && line[i - 1] != '>')
    || (line[i] == '<' && line[i + 1] == '<' && line[i - 1] != '<'
    && line[i + 2] != '<')
    || (line[i] == '<' && line[i + 1] != '<' && line[i - 1] != '<'))
        return 1;
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
        if (check_separ(line, i) == 1) {
            if ((line[i] == '>' && line[i + 1] == '>') ||
                (line[i] == '<' && line[i + 1] == '<'))
                list = find_rafters(line[i], shell);
            else if ((line[i] == '>' && line[i + 1] != '>') ||
                (line[i] == '<' && line[i + 1] != '<'))
                list = find_rafters2(line[i], shell);
            value = 1;
            if (!(list)) return 0;
            else {
                if ((value = list(envp, line, shell, x)) == 1)
                    return 1;
            }
        }
        i++;
    }
    return value;
}