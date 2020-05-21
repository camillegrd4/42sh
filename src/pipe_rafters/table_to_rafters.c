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