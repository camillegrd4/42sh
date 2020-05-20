/*
** EPITECH PROJECT, 2020
** separator
** File description:
** separator
*/

#include "my.h"

const separ_t map[] = {
    { "||", &do_double_or },
    { "&&", &do_double_and },
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

int line_value(char line)
{
    int i = 0;

    if (line == '\n')
        return 1;
    return 0;
}

int call_separator(char **envp, shell_t *shell, char *line, int x)
{
    cmd_t *cmd = NULL;
    cmd_t *tmp = NULL;
    separator_t separator = NULL;
    char *tmp_str = NULL;

    if (line_value(line[0]) == 1) return 0;
    tmp_str = clean_str(line);
    cmd = parse_cmd(tmp_str);
    if (check_invalid_command(cmd) == 2)
        return 2;
    tmp = cmd;
    while (tmp) {
        separator = find_separator(tmp, shell);
        if (!(separator)) {
            return 0;
        } else
            x = separator(envp, tmp->cmd, shell, x);
        tmp = tmp->next;
    }
    free_list(cmd);
    cmd = NULL;
    return 2;
}