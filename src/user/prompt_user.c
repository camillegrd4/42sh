/*
** EPITECH PROJECT, 2020
** prompt user
** File description:
** prompt_user
*/

#include "my.h"
#include <limits.h>

char *get_current_folder(void)
{
    char cwd[PATH_MAX];
    getcwd(cwd, sizeof(cwd));
    int i = 0;
    char **array = str_to_wordtab(cwd, "/");

    while (array[i] && i < 15)
        i++;
    if (i > 15)
        return NULL;
    else {
        return array[i - 1];
    }
}

void prompt_user(shell_t *shell)
{

    char *folder = get_current_folder();

    if (folder)
        printf("%s $> ", folder);
    else
        my_putstr("$> ");
}