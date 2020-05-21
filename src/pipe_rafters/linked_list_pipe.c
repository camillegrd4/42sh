/*
** EPITECH PROJECT, 2020
** linked_list
** File description:
** list
*/

#include "my.h"

piping_t *my_rev_pipe(piping_t *begin)
{
    piping_t *tmp = 0;
    piping_t *elem = begin;
    piping_t *next;

    while (elem->next) {
        next = elem->next;
        elem->next = tmp;
        tmp = elem;
        elem = next;
    }
    elem->next = tmp;
    return elem;
}

piping_t *add_element(piping_t *head, char *str)
{
    piping_t *tmp = malloc(sizeof(piping_t));
    int i = 0;

    if (!tmp)
        return NULL;
    tmp->tab = str_to_wordtab(str, " ");
    tmp->next = head;
    return tmp;
}

piping_t *get_path(char **tab)
{
    piping_t *head = NULL;
    int i = 0;

    while (tab[i]) {
        head = add_element(head, tab[i]);
        i++;
    }
    return (my_rev_pipe(head));
}