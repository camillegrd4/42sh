/*
** EPITECH PROJECT, 2020
** rafters
** File description:
** rafters
*/

#include "my.h"

int missing_command(int number_arg, int number_rafters)
{
    if (number_arg == 0) {
        printf("Missing name for redirect.\n");
        return 1;
    } else if (number_arg + 1 < number_rafters) {
        printf("Missing name for redirect.\n");
        return 1;
    } else if (number_arg == number_rafters) {
        printf("Missing name for redirect.\n");
        return 1;
    }
    return 0;
}

int check_arg_double_rev_rafters(char **check)
{
    int i = 0;

    while (check[i]) {
        if (i == 0 && my_strncmp(check[i], "<<", 2) == 0 && check[i + 1]) {
            printf("Invalid null command.\n");
            return 1;
        }
        i++;
    }
    return 0;
}

int check_line_double_rev_rafters(char *line)
{
    char **check = str_to_wordtab(line, " ");
    int i = 0;
    int j = 0;
    int number_arg = 0;
    int number_rafters = 0;

    check = clean_string(check);
    if (check_arg_double_rev_rafters(check) == 1)
        return 1;
    while (check[i]) {
        if (my_strncmp(check[i], "\0", 1) != 0
                && my_strncmp(check[i], "<<", 2) != 0)
            number_arg++;
        else if (my_strncmp(check[i], "\0", 1) != 0
                && my_strncmp(check[i], "<<", 2) == 0)
            number_rafters++;
        i++;
    }
    if (missing_command(number_arg, number_rafters) == 1)
        return 1;
    return 0;
}