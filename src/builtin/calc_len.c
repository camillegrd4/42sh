/*
** EPITECH PROJECT, 2020
** calc
** File description:
** calc
*/

#include "my.h"


int calc_len(char *str)
{
    int i = 0;
    int value = 0;

    while (str[i] != '=')
        i++;
    while (str[i] != '\0') {
        value++;
        i++;
    }
    return value;
}