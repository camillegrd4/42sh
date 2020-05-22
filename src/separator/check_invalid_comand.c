/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** check invalid null command
*/

#include "my.h"

int check_invalid_command(cmd_t *cmd)
{
    cmd_t *tmp;

    if (!cmd)
        return 2;
    tmp = cmd;
    while (tmp) {
        if (tmp->more_sep == true || !tmp->cmd ||
        my_strcmp(tmp->cmd, " ") == 0 || my_strcmp(tmp->cmd, "\t") == 0) {
            my_putstr("Invalid null command.\n");
            return 2;
        }
        tmp = tmp->next;
    }
    return 0;
}