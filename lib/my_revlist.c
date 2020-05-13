/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** my revlist
*/

#include "my.h"

void my_rev_list(cmd_t **begin)
{
    cmd_t *tmp = 0;
    cmd_t *elem = *begin;
    cmd_t *next;

    while (elem->next) {
        next = elem->next;
        elem->next = tmp;
        tmp = elem;
        elem = next;
    }
    elem->next = tmp;
    *begin = elem;
}