/*
** EPITECH PROJECT, 2020
** separator
** File description:
** separator
*/

#include "my.h"

const separ_t map[] = {
    { "||", &do_double_or },
    { "&&", &check_time },
    { ";", &call_exec_comma_function },
    {"NULL"},
};

separator_t find_separator(cmd_t *cmd, shell_t *shell)
{
    int i = 0;
    while (&map[i]) {
        if (my_strcmp(map[i].value, cmd->separator) == 0) {
            return (map[i].separator);
        }
        if (my_strcmp(map[i].value, "NULL") == 0)
            return 0;
        i++;
    }
    return NULL;
}

int call_separator(char **envp, shell_t *shell, char *line, int x)
{
    cmd_t *cmd = parse_cmd(line);
    separator_t separator = NULL;

    while (cmd) {
        separator = find_separator(cmd, shell);
        if (!(separator)) {
            return 0;
        } else {
            if (separator(envp, cmd->cmd, shell, x) == 1) {
                return 1;
            }
        }
        cmd = cmd->next;
    }
    free_list(cmd);
    return 2;
}