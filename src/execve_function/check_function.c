/*
** EPITECH PROJECT, 2020
** check
** File description:
** check
*/

#include "my.h"

char *check_path(char *path)
{
    int i = 0;
    int x = 0;
    char *change_path = malloc(sizeof(char) * (my_strlen(path)) + 1);

    while (path[i] != '\0') {
        if (path[i] == '.' && path[i + 1] == '/') {
            i += 2;
        }
        change_path[x] = path[i];
        i++;
        x++;
    }
    change_path[x] = '\0';
    return change_path;
}

int check_error_father(int wstatus)
{
    if (WIFSIGNALED(wstatus)) {
        if (WTERMSIG(wstatus) != 8)
            my_putstr(strsignal(WTERMSIG(wstatus)));
        else {
            my_putstr("Floating exception");
        }
        if (WCOREDUMP(wstatus))
            my_putstr(" (core dumped)");
        my_putchar('\n');
        return 1;
    }
    return 0;
}