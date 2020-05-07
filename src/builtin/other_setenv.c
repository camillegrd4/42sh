/*
** EPITECH PROJECT, 2020
** other setenv
** File description:
** pther setenv
*/

#include "my.h"

int my_str_isalpha_num(char const *str)
{
    int i = 0;

    if (str == NULL)
        return 84;
    while (str[i]) {
        if ((str[i] < '0' || str[i] > '9') &&
            (str[i] < 'A' || str[i] > 'Z') &&
            (str[i] < 'a' || str[i] > 'z'))
            return 1;
        i++;
    }
    return 0;
}

char *my_strcat_env(char *dest, char *src)
{
    int	i = 0;
    int	j = 0;
    char *str = malloc(sizeof(str) * (my_strlen(dest) + my_strlen(src) + 2));

    while (dest[i] != 0) {
        str[i] = dest[i];
        i++;
    }
    while (src[j]) {
        str[i] = src[j];
        j++;
        i++;
    }
    str[i] = '\0';
    return (str);
}

int tab_size(char **env)
{
    int i = 0;

    while (env[i] != NULL)
        i++;
    return i;
}

char **setnew_env(shell_t *shell)
{
    char **new_one = NULL;
    int i = 0;
    
    if (shell->save_env == NULL)
        return NULL;
    new_one = malloc(sizeof(char *) * (tab_size(shell->save_env) + 2));
    while (shell->save_env[i]) {
        new_one[i] = my_strdup(shell->save_env[i]);
        free(shell->save_env[i]);
        i++;
    }
    new_one[i] = my_strcat_env(shell->array[1], "=");
    if (tab_size(shell->array) == 3)
        new_one[i] = my_strcat_env(new_one[i], shell->array[2]);
    new_one[i + 1] = NULL;
    return new_one;
}

int setting_env(char **env, shell_t *shell)
{
    if (tab_size(shell->array) > 3) {
        my_putstr("setenv: Too many arguments.\n");
        return 1;
    }
    if ((shell->array[1][0] < 'a' || shell->array[1][0] > 'z') &&
        (shell->array[1][0] < 'A' || shell->array[1][0] > 'Z')) {
        my_putstr("setenv: Variable name must begin with a letter.\n");
        return 1;
    } else if (my_str_isalpha_num(shell->array[1]) == 1) {
        my_putstr("setenv: Variable name must contain "
                  "alphanumeric characters.\n");
        return 1;
    } else
        shell->save_env = setnew_env(shell);
    return 0;
}