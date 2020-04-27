/*
** EPITECH PROJECT, 2020
** struct
** File description:
** struct
*/

#ifndef STRUCT_H
#define STRUCT_H

typedef struct shell {
    char *cmd;
    char **array;
    char *path;
    char **path_bis;
    char **save_env;
    char *name;
    char *remove;
    char **new_env;
    int line;
    char *unset;
    int pos;
    struct comma_s *comma;
}shell_t;

typedef struct comma_s {
    char *first_arg;
    char *second_arg;
    char *first_arg_pipe;
    char *second_arg_pipe;
}comma_t;

#endif /* !STRUCT_H */
