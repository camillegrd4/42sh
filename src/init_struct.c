/*
** EPITECH PROJECT, 2020
** init
** File description:
** init
*/

#include "my.h"

shell_t *init_struct_minishell(char **envp)
{
    int i = 0;

    if (!envp)
        return NULL;
    shell_t *shell = malloc(sizeof(shell_t));
    if (!shell)
        return NULL;
    shell->array = NULL;
    shell->cmd = NULL;
    shell->path = NULL;
    shell->path_bis = NULL;
    shell->save_env = NULL;
    shell->name = NULL;
    shell->new_env = NULL;
    shell->line = 0;
    shell->unset = NULL;
    shell->pos = 0;
    shell->comma = malloc(sizeof(comma_t));
    return shell;
}