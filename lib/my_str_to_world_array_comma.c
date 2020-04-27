/*
** EPITECH PROJECT, 2019
** my
** File description:
** my
*/

#include "my.h"

int number_char_comma(char *str, int i)
{
    int number_char = 0;

    if (!str)
        return 84;
    while (str[i] != '\0') {
        if (str[i] == ';' || str[i] == '\0')
            number_char += 1;
        i += 1;
    }
    return number_char;
}

int lines_comma(char *str)
{
    int i = 0;

    if (!str)
        return 84;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

char **add_letter_comma(char **array, int number, char *str, int i)
{
    int j = 0;
    int a = 0;

    while (number > 0 && i <= my_strlen(str)) {
        while (str[i] == ';')
            i++;
        array[a] = malloc(sizeof(char) * (lines_comma(&str[i]) + 2));
        while (str[i] != '\0' && str[i] != '\n' && str[i] != ';') {
            array[a][j] = str[i];
            j += 1;
            i += 1;
        }
        array[a][j] = '\0';
        j = 0;
        a += 1;
        --number;
    }
    array[a] = NULL;
    return array;
}

char **my_str_to_world_array_comma(char *str)
{
    int number = 0;
    char **array = NULL;
    char **form = NULL;
    int i = 0;
    int a = 0;

    while (str[i] == ' ') {
        i++;
    }
    number = number_char_comma(str, i) + 1;
    array = malloc(sizeof(char *) * (number + 2));
    array = add_letter_comma(array, (number), str, i);
    return array;
}