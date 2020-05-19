/*
** EPITECH PROJECT, 2020
** change
** File description:
** change
*/

#include "my.h"

char *change_string_next(char *compare, char *line, int x, int i)
{
    while (line[i]) {
        if (line[i] == '\"')
            i++;
        compare[x] = line[i];
        i++;
        x++;
    }
    compare[x] = '\n';
    return compare;
}

char *clean_compare(char *compare)
{
    int i = 0;
    int j = 0;
    char *change_string = malloc(sizeof(char) * (my_strlen(compare) + 2));

    while (compare[i] != '\0') {
        if (compare[i] == '\"' || compare[i] == '\n') {
            i++;
        } else {
            change_string[j] = compare[i];
            j++;
            i++;
        }
    }
    change_string[j] = '\n';
    change_string[++j] = '\0';
    printf("change_string-->[%s]\n", change_string);
    return change_string;
}

char *change_string(char *str, char *line, int j, int i)
{
    int x = 0;
    int y = 0;
    char *compare = calloc((my_strlen(line) + calc_len(str) + 2),
        sizeof(char));

    while (y != i - 1) {
        compare[x] = line[y];
        y++;
    }
    while (str[j] != '=')
        j++;
    j++;
    while (str[j] != '\0') {
        compare[x] = str[j];
        j++;
        x++;
    }
    compare = change_string_next(compare, line, x, i);
    printf("compare--->[%s]\n", compare);
    compare = clean_compare(compare);
    printf("compare_2--->[%s]\n", compare);
    return compare;
}