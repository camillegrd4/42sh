/*
** EPITECH PROJECT, 2020
** my
** File description:
** my
*/

#ifndef MY_H
#define MY_H

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <fcntl.h>
#include "stdbool.h"
#include "struct.h"

/*src*/
char minishel(char **argv, char **envp);
int my_function(shell_t *shell, char **envp);
int cd_function(shell_t *shell);
int exec_function(char **envp, shell_t *shell, pid_t pid);
int find_path(shell_t *shell, char **envp);
shell_t *init_struct_minishell(char **envp);
int exit_function(shell_t *shell);
int unsetenv_function(shell_t *shell);
int execve_function(char **envp, shell_t *shell);
void redirect_all_stdout(void);
int call_function_recode(char **envp, shell_t *shell);
int call_function_recode_next(char **envp, shell_t *shell);
int setenv_function(char **envp, shell_t *shell);
char **create_list_env(char **envp, shell_t *shell);
int print_env(char **str, shell_t *shell);
int change_env(char **envp, shell_t *shell);
int count_line(char **envp, shell_t *shell);
char **add_line(char **envp, shell_t *shell);
int change_save_env(char **envp, shell_t *shell);
int find_line(shell_t *shell, int i, int j, int y);
char *change_line(shell_t *shell, int i, int y);
int change_env_next(shell_t *shell, int line);
int my_unsetenv(shell_t *shell);
char **remove_line(shell_t *shell, int i, int y);
int access_function(int i, char **envp, char *path, shell_t *shell);
int exec_binary(shell_t *shell, char **envp);
int exec_function_system(shell_t *shell, char **envp, int i);
char *check_path(char *path);
int check_error_father(int wstatus);
int check_getline(shell_t *shell, char **envp, int x, char *line);
int call_exec_comma_function(char *line, shell_t *shell, char **envp);
int check_line(char *line, shell_t *shell, int i);
int exec_cd(shell_t *shell, char *path);
int check_pipe(char **envp, char *line, shell_t *shell, int i);
char *fill_second_arg(shell_t *shell, int i, char *line);
char *fill_first_arg(shell_t *shell, char *line);
int check_function(char **envp, shell_t *shell, char *line, int i);
int check_comma_function(char *line, shell_t *shell, char **envp, int x);
int check_pipe_function(char **envp, char *line, shell_t *shell, int i);
int exec_first_arg(char **envp, char *line, shell_t *shell, int i);
char **add_letter_colon(char **array, int number, char *str, int i);
char **check_space_colon(char **array, int number, char **form);

/*lib*/
int my_strlen_comma(char const *str);
int my_putchar(char c);
int my_putstr(char const *str);
char **my_str_to_world_array(char *str);
int my_strlen(char const *str);
char *my_strcat(char *dest, char const *src);
int my_strncmp(char const *s1, char const *s2, int n);
int my_strcmp(char const *s1, char const *s2);
char **my_str_to_world_array_pipe(char *str);
char *my_strdup(char const *src);
int number_char(char *str, int i);
int lines(char *str);
int number_char_colon(char *str, int i);
int lines_colon(char *str);
int cd_function(shell_t *shell);
int my_strncmp_next(char const *s1, char const *s2, int n);
char *my_strcat_two(char *dest, char const *src);
int my_putstr_without_return(char const *str);
int my_strlen_env(char *str);
int my_strlen_egale(char const *str);
int my_strlen_pipe(char const *str);
char **my_str_to_world_array_comma(char *str);
char **check_space_comma(char **array, int number, char **form);
char **add_letter_comma(char **array, int number, char *str, int i);

/*criterion*/
void redirect_all_stdout(void);

#endif /* !MY_H */
