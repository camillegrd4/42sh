/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** check invalid null command
*/

#include "my.h"

int check_pipes(char *cmd)
{
    char *temp = clean_str(cmd);

    printf("%s\n", temp);
    if (!strcmp(temp, "|") || !strcmp(temp, " |") || !strcmp(temp, "| "))
        return 1;
    return 0;
}

int check_invalid_command(cmd_t *cmd)
{
    cmd_t *tmp;

    if (!cmd)
        return 2;
    tmp = cmd;
    while (tmp) {
        if (tmp->more_sep == true || !tmp->cmd || check_pipes(tmp->cmd)) {
            my_putstr("Invalid null command.\n");
            return 2;
        }
        tmp = tmp->next;
    }
    return 0;
}