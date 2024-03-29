/*
** EPITECH PROJECT, 2020
** init
** File description:
** init
*/

#include "my.h"

shell_t *init_struct_minishell_next(char **envp, shell_t *shell)
{
    if (!envp)
        return NULL;
    shell->unset = NULL;
    shell->pos = 0;
    shell->echo_path = NULL;
    shell->command_done = 0;
    shell->username = get_username();
    shell->host = get_host();
    shell->comma = malloc(sizeof(comma_t));
    return shell;
}

shell_t *init_struct_minishell(char **envp)
{
    int i = 0;
    char *buf = NULL;
    size_t n = 0;

    if (!envp)
        return NULL;
    shell_t *shell = malloc(sizeof(shell_t));
    if (!shell)
        return NULL;
    shell->first_path = getcwd(buf, n);
    shell->array = NULL;
    shell->cmd = NULL;
    shell->path = NULL;
    shell->path_bis = NULL;
    shell->save_env = NULL;
    shell->name = NULL;
    shell->new_env = NULL;
    shell->line = 0;
    if (!(init_struct_minishell_next(envp, shell)))
        return NULL;
    return shell;
}