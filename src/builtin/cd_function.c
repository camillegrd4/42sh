/*
** EPITECH PROJECT, 2020
** cd
** File description:
** cd
*/

#include "my.h"

int exec_cd(shell_t *shell, char *path)
{
    errno = 0;
    if (chdir(path) == -1) {
        if (errno == EACCES) {
            my_putstr("error: Permission denied.\n");
            return 1;
        }
        if (errno == ENOENT) {
            my_putstr(path);
            my_putstr(": No such file or directory.\n");
            return 1;
        }
        if (errno == ENOTDIR) {
            my_putstr(path);
            my_putstr(": Not a directory.\n");
            return 1;
        }
    }
    return 0;
}

int cd_normal(shell_t *shell, char *path)
{
    static int value = 0;

    if (value == 0 && my_strncmp(path, "-", 2) == 0) {
        my_putstr(": No such file or directory.\n");
        return 1;
    } else if (value == 1 && my_strncmp(path, "-", 2) == 0)
        path = "..";
    if (exec_cd(shell, path) == 1)
        return 1;
    value = 1;
    return 0;
}

int cd_function(shell_t *shell)
{
    if (!shell || !shell->array[0])
        return 84;
    if (my_strncmp(shell->array[1], "-", 1) == 0) {
        if (cd_normal(shell, "-") == 1)
            return 1;
    } else {
        if (cd_normal(shell, shell->array[1]) == 1)
            return 1;
    }
    return 0;
}