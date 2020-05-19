/*
** EPITECH PROJECT, 2020
** prompt user
** File description:
** prompt_user
*/

#include "my.h"
#include <limits.h>

void prompt_user(shell_t *shell)
{
    char cwd[PATH_MAX];

    getcwd(cwd, sizeof(cwd));
    if (shell->username && isatty(STDIN_FILENO) && shell->host && cwd)
        printf("%s@%s || %s $> ", shell->username, shell->host, cwd);
    else
        my_putstr("$>");
}