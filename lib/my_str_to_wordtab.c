/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** pth str tab
*/

#include "my.h"

int is_separator(char lettre, char const *separator)
{
    int i = 0;

    while (separator[i]) {
        if (separator[i] == lettre)
            return 0;
        i++;
    }
    return 1;
}

int    get_tab_size(char const *str, char const *separator)
{
    int size = 1;
    int i = 0;

    while (str[i]) {
        if (is_separator(str[i], separator) == 0 &&
        is_separator(str[i + 1], separator) == 1 && str[i + 1])
            size++;
        i++;
    }
    return (size);
}

int    get_word_size(char const *str, char const *separator)
{
    int i = 0;

    while (is_separator(str[i], separator) == 1 && str[i])
        i++;
    return (i);
}

char **str_to_wordtab(char const *str, char const *separator)
{
    char **dest = NULL;
    int i = 0;
    int j = 0;
    int k = 0;
    int size = get_tab_size(str, separator);

    if (!(dest = malloc(sizeof(char *) * (size + 1)))) return (NULL);
    while (str[i]) {
        while (is_separator(str[i], separator) == 0 && str[i])
            i++;
        size = get_word_size(&str[i], separator);
        if (!(dest[j] = malloc(sizeof(char) * (size ) + 1))) return (NULL);
        while (k < size)
            dest[j][k++] = str[i++];
        dest[j][k] = '\0';
        k = 0;
        j++;
    }
    dest[j] = NULL;
    return (dest);
}