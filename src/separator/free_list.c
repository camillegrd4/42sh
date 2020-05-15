/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** free list
*/

#include "my.h"

void free_list(cmd_t **head)  
{
    cmd_t *curr;

    while ((curr = *head) != NULL) { // set curr to head, stop if list empty.
        *head = (*head)->next;          // advance head to next element.
        free (curr);                // delete saved pointer
    }
}
 