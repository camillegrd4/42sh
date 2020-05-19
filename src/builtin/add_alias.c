/*
** EPITECH PROJECT, 2020
** add
** File description:
** add
*/

#include "my.h"

int alias_function(char **envp, shell_t *shell)
{
    FILE *fd = fopen("alias.txt", "a+");
    int i = 1;

    if (!fd)
        return 84;
    if (shell->array[1]) {
        while (shell->array[i]) {
            fprintf(fd, "%s ", shell->array[i]);
            i++;
        }
        fprintf(fd, "%s", "\n");
        fprintf(fd, "%c", '\0');
        fclose(fd);
    } else {
        my_putstr("Error\n");
    }
    return 0;
}