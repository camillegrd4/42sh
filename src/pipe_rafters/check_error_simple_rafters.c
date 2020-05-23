/*
** EPITECH PROJECT, 2020
** check
** File description:
** check
*/

#include "my.h"

int check_arg_simple_rafters(char **check)
{
    int i = 0;
    int arg = calc_number_char(check) - 1;

    while (check[i]) {
        if (i == 0 && my_strncmp(check[i], ">", 2) == 0 && check[i + 1]) {
            printf("Invalid null command.\n");
            return 1;
        }
        i++;
    }
    return 0;
}

int print_error(char **check, int number_arg, int number_pipe,
int number_rafters)
{
    if (my_strncmp(check[0], "cat", 3) == 0
    && (number_arg != number_rafters)) {
        printf("Ambiguous output redirect.\n");
        return 1;
    }
    if (missing_command(number_arg, number_rafters) == 1)
        return 1;
    return 0;
}

int check_line_simple_rafters(char *line)
{
    char **check = clean_string(str_to_wordtab(line, " "));
    int i = 0;
    int j = 0;
    int number_arg = 0;
    int number_rafters = 0;
    int number_pipe = 0;
    if (check_arg_simple_rafters(check) == 1) return 1;
    while (check[i]) {
        if (my_strncmp(check[i], "\0", 1) != 0 &&
        my_strncmp(check[i], ">", 2) != 0 && my_strncmp(check[i], "|", 2) != 0)
            number_arg++;
        else if (my_strncmp(check[i], "|", 1) == 0)
            number_pipe++;
        else if (my_strncmp(check[i], "\0", 1) != 0
                && my_strncmp(check[i], ">", 2) == 0)
            number_rafters++;
        i++;
    }
    if (print_error(check, number_arg, number_pipe, number_rafters) == 1)
        return 1;
    return 0;
}