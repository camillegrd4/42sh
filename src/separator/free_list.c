/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** free list
*/

#include "my.h"

void free_keys(cmd_t **cmd)
{
    cmd_t *tmp;

    if (!cmd)
        return;
    while (*cmd) {
        tmp = *cmd;
        *cmd = (*cmd)->next;
        free(tmp);
    }
}