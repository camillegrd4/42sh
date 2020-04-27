/*
** EPITECH PROJECT, 2019
** my
** File description:
** my
*/

#include "my.h"

int number_char(char *str, int i)
{
    int number_char = 0;

    if (!str)
        return 84;
    while (str[i] != '\0') {
        if ((str[i] == ' ' || str[i] == '\t' || str[i] == ';'
        && str[i + 1] != ' ' && str[i + 1] != '\t'))
            number_char += 1;
        i += 1;
    }
    return number_char;
}

int lines(char *str)
{
    int i = 0;

    if (!str)
        return 84;
    while (str[i] != '\0') {
        i += 1;
    }
    return i;
}

char **add_letter(char **array, int number, char *str, int i)
{
    int j = 0;
    int a = 0;

    while (number > 0 && i <= my_strlen(str)) {
        while (str[i] == ' ' || str[i] == '\t' || str[i] == ':')
            i++;
        array[a] = malloc(sizeof(char) * (lines(&str[i]) + 2));
        while (str[i] != '\0' && str[i] != '\t'
        && str[i] != ' ' && str[i] != '\n' || str[i] == ';') {
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

char **check_space(char **array, int number, char **form)
{
    int j = 0;
    int a = 0;
    int i = 0;
    int x = 0;
    while (array[i]) {
        j = 0;
        x = 0;
        form[a] = malloc(sizeof(char) * (my_strlen(array[i]) + 2));
        if (!form) return NULL;
        while (array[i][j]) {
            if (array[i][j] == ' ' || array[i][j] == '[' || array[i][j] == ']')
                j++;
            else if (array[i][j])
                form[a][x++] = array[i][j++];
        }
        if (x != 0)
            form[a++][x] = '\0';
        i++;
    }
    form[a] = NULL;
    return form;
}

char **my_str_to_world_array(char *str)
{
    int number = 0;
    char **array = NULL;
    char **form = NULL;
    int i = 0;
    int a = 0;

    while (str[i] == ' ') {
        i++;
    }
    number = number_char(str, i) + 1;
    array = malloc(sizeof(char *) * (number + 2));
    array = add_letter(array, number, str, i);
    form = malloc(sizeof(char *) * (number + 2));
    array = check_space(array, (number), form);
    return array;
}