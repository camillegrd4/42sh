/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** parse cmd
*/

#include "my.h"

cmd_t *add_to_list(char *cmd, char *separator, cmd_t *cmd_list)
{
    cmd_t *tmp = malloc(sizeof(cmd_t));

    if (!tmp)
        return NULL;
    tmp->separator = separator;
    tmp->cmd = my_strdup(cmd);
    tmp->more_sep = false;
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
    char *new = calloc(sizeof(char) * 1000, sizeof(char));
    int j = 0;

    while (is_end(line[*i]) != 1 &&
            is_not_separator(line[*i], line[*i + 1], line[*i - 1])) {
        new[j] = line[*i];
        j++;
        (*i)++;
    }
    new[j] = '\0';
    return new;
}

cmd_t *final_check(cmd_t *new_cmd, char *separator, bool too_much_sep)
{
    if (!new_cmd && too_much_sep == true)
        return add_to_list(NULL, "||", new_cmd);
    if ((strcmp(separator, ";") != 0 || too_much_sep == true) && new_cmd)
        new_cmd->more_sep = true;
    my_rev_list(&new_cmd);
    return new_cmd;
}

cmd_t *parse_cmd(char *line)
{
    cmd_t *new_cmd = NULL;
    int i = 0;
    char *one_cmd = NULL;
    char *separator = ";";
    bool too_much_sep = false;
    bool not_fst = false;

    while (line[i]) {
        one_cmd = return_one_cmd(line, &i);
        if (is_pipe(line[i], line[i + 1], line[i - 1]) &&
            (!one_cmd || one_cmd[0] == '\0') && not_fst == false)
            too_much_sep = true;
        if (one_cmd[0] != '\0') {
            not_fst = true;
            new_cmd = add_to_list(one_cmd, separator, new_cmd);
            separator = which_sep(line[i], line[i + 1], line[i - 1]);
        }
        if (one_cmd) free(one_cmd);
        i++;
    }
    return final_check(new_cmd, separator, too_much_sep);
}