/*
** EPITECH PROJECT, 2020
** echo
** File description:
** echo
*/

#include "my.h"

int flags_e(char *str)
{
    int i = 2;
    int j = 0;

    while (str[j] != '\0') {
        if (str[j] == '"')
            j++;
        if (str[j] == '\\' && str[j + 1] == 'n') {
            my_putchar('\n');
            j += 2;
        }
        my_putchar(str[j]);
        j++;
    }
    my_putchar('\n');
    return 0;
}