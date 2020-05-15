/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** free list
*/

#include "my.h"

void free_list(cmd_t *head)
{
    cmd_t *curr = head;
    cmd_t *to_free = head;

    while (to_free != NULL) {
        curr = curr->next;
        free(to_free->cmd);
        free(to_free);
        to_free = curr;
    }
}
