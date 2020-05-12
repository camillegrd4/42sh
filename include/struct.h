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
    char *echo_path;
    int value;
    int without;
    int error;
    int command_done;
    struct comma_s *comma;
}shell_t;

typedef struct comma_s {
    char *first_arg;
    char *second_arg;
    char *first_arg_pipe;
    char *second_arg_pipe;
}comma_t;

typedef int (*builtin_t)(char **envp, shell_t *shell);

typedef struct recode {
    const char *key;
    builtin_t builtin;
} recode_t;

extern const recode_t tab[];

#endif /* !STRUCT_H */
