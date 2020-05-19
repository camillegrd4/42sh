/*
** EPITECH PROJECT, 2020
** get _host
** File description:
** get_host
*/

#include "my.h"

char *get_host()
{
    char hostname[1024];
    char *result = NULL;

    hostname[1023] = '\0';
    gethostname(hostname, 1023);
    result = my_strdup(hostname);
    if (!hostname)
        return NULL;
    else
        return result;
}