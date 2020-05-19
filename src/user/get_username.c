/*
** EPITECH PROJECT, 2020
** get username
** File description:
** get_username
*/

#include "my.h"

char *get_username()
{
    char *username = getenv("USER");

    if (!username)
        return NULL;
    else 
        return username;
}