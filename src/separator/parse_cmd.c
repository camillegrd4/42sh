/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** parse cmd
*/

#include "my.h"

int is_not_separator(char current, char plus_one)
{
    if (current == ';' ||
        (current == '|' && plus_one == '|') ||
        (current == '&' && plus_one == '&'))
        return 0;
    return 1;
}

char *which_sep(char current, char plus_one, char minus_one)
{
    if (current == ';')
        return ";";
    if (current == '|' && (plus_one == '|' || minus_one == '|'))
        return "||";
    if (current == '&' && (plus_one == '&' || minus_one == '&'))
        return "&&";
    return ";";
}

cmd_t *add_to_list(char *cmd, char *separator, cmd_t *cmd_list)
{
    cmd_t *tmp = malloc(sizeof(cmd_t));

    if (!tmp)
        return NULL;
    tmp->separator = separator;
    tmp->cmd = my_strdup(cmd);
    tmp->next = cmd_list;
    return tmp;
}

int is_end(char c)
{
    const char str[2] = "\0\n";
    int i = 0;

    while (i != sizeof(str)) {
        if (c == str[i])
            return 1;
        i++;
    }
    return 0;
}

char *return_one_cmd(char *line, int *i)
{
    char *new = calloc(sizeof(char) * 15, sizeof(char));
    int j = 0;

    while (is_not_separator(line[*i], line[*i + 1]) && is_end(line[*i]) != 1) {
        new[j] = line[*i];
        j++;
        (*i)++;
    }
    new[j] = '\0';
    return new;
}

cmd_t *parse_cmd(char *line)
{
    cmd_t *new_cmd = NULL;
    int i = 0;
    char *one_cmd = NULL;
    char *separator = ";";

    while (line[i]) {
        one_cmd = return_one_cmd(line, &i);
        if (one_cmd[0] != '\0') {
            new_cmd = add_to_list(one_cmd, separator, new_cmd);
            separator = which_sep(line[i], line[i + 1], line[i - 1]);
        }
        free(one_cmd);
        i++;
    }
    my_rev_list(&new_cmd);
    return new_cmd;
}