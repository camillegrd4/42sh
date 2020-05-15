/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** free list
*/

#include "my.h"

void free_list(cmd_t **cmd)
{
    cmd_t *tmp;

    if (!cmd)
        return;
    while (*cmd) {
        tmp = *cmd;
        *cmd = (*cmd)->next;
        free(tmp->cmd);
        free(tmp->separator);
        free(tmp);
    }
}