/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** free list
*/

#include "my.h"

void free_list(cmd_t **head_ref)  
{
    cmd_t *current = *head_ref;
    cmd_t *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        free(current->separator);
        free(current->cmd);
        current = next;
    }
    *head_ref = NULL;  
}
 