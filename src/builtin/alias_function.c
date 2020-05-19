/*
** EPITECH PROJECT, 2020
** alias
** File description:
** alias
*/

#include "my.h"
#define TAILLE_MAX 1000

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

int compare(char *line, char *str, int j, int i)
{
    while (line[i] != ' ' && line[i] != '\n') {
        if (str[j] != line[i])
            return -1;
        j++;
        i++;
    }
    return i;
}

char *compare_string(char *str, char *line)
{
    int i = 0;
    int j = 0;

    if ((i = compare(line, str, j, i)) == -1)
        return NULL;
    else {
        line = change_string(str, line, j, i);
        return line;
    }
    return NULL;
}

char *check_alias(char *line)
{
    FILE *fd = fopen("alias.txt", "a+");
    char str[TAILLE_MAX] = "";
    char *string = NULL;

    if (fd != NULL) {
        fseek(fd, 0, 0);
        while (fgets(str, TAILLE_MAX, fd) != NULL) {
            if ((string = compare_string(str, line)) != NULL) {
                return string;
            }
        }
        fclose(fd);
    }
    return line;
}