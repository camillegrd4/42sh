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
#include <limits.h>
#include "stdbool.h"
#include "struct.h"

/*src*/
char minishel(char **argv, char **envp);
int my_function(shell_t *shell, char **envp);
int exec_function(char **envp, shell_t *shell, pid_t pid);
int find_path(shell_t *shell, char **envp);
shell_t *init_struct_minishell(char **envp);
int execve_function(char **envp, shell_t *shell);
int access_function(int i, char **envp, char *path, shell_t *shell);
int exec_binary(shell_t *shell, char **envp);
int exec_function_system(shell_t *shell, char **envp, int i);
int print_n_flags_backslash_n(shell_t *shell, int i);


/*comma_pipe*/
char *check_path(char *path);
int check_error_father(int wstatus);
int check_getline(shell_t *shell, char **envp, int x, char *line);
int check_line(char *line, shell_t *shell, int i);
int exec_cd(shell_t *shell, char *path);
int check_pipe(char **envp, char *line, shell_t *shell, int i);
char *fill_second_arg(shell_t *shell, int i, char *line);
char *fill_first_arg(shell_t *shell, char *line);
int check_function(char **envp, shell_t *shell, char *line, int i);
int check_comma_function(char **envp, char *line, shell_t *shell, int x);
int check_pipe_function(char **envp, char *line, shell_t *shell, int i);
int check_error_main(char **envp, char *line, shell_t *shell, int x);
int exec_first_arg(char **envp, char *line, shell_t *shell, int x);
int double_rafter(char **, char *, shell_t *, int);
int double_rev_rafter(char **, char *, shell_t *, int);
int call_exec_comma_function(char **envp, char *line, shell_t *shell, int x);
int redirections_function(char **envp, char *line, shell_t *shell, int x);
int reverse_function(char **envp, char *line, shell_t *shell, int x);
int call_rafters(char *line, char **envp, shell_t *shell, int x);
int check_error(shell_t *shell);
list_t find_rafters2(char str, shell_t *shell);
list_t find_rafters(char str, shell_t *shell);
piping_t *get_path(char **tab);
static int exec_father(pid_t pid, shell_t *shell, char **envp, int fd[2]);
static int exec_child(shell_t *shell, pid_t pid, char **envp, int *fd);
static int exec_arg(pid_t pid, shell_t *shell, char **envp, int *fd);

/*builtin*/
int setting_env(char **envp, shell_t *shell);
int cd_function(char **envp, shell_t *shell);
int exit_function(char **argv, shell_t *shell);
int unsetenv_function(char **envp, shell_t *shell);
int my_unsetenv(shell_t *shell);
int change_env_next(shell_t *shell, int line, char **envp);
char *change_line(shell_t *shell, char **envp, int i, int y);
int call_builtin(char **envp, shell_t *shell);
int setenv_function(char **envp, shell_t *shell);
char **create_list_env(char **envp, shell_t *shell);
int print_env(char **envp, shell_t *shell);
int change_env(char **envp, shell_t *shell);
int count_line(char **envp, shell_t *shell);
char **add_line(char **envp, shell_t *shell);
int change_save_env(char **envp, shell_t *shell);
int find_line(char **envp, shell_t *shell, int j, int y);
char **remove_line(shell_t *shell, int i, int y);
int echo_builtin(char **envp, shell_t *shell);
int flags_n(shell_t *shell);
char *recover_arg(char **arg);
int print_arg(shell_t *shell);
int calc_len_arg(char **arg);
int my_pattern(shell_t *shell, char path);
int check_cot(char *str, int i);
int print_n_flags(shell_t *shell, int j);
int my_main_flags(char str);
int backslash_b(shell_t *shell);
int backslash_n(shell_t *shell);
int print_n_flags_normal(shell_t *shell, int j);
int print_e_flags_without_changes(shell_t *shell);
int my_flags(char str);
int backslash_c(shell_t *shell);
int backslash_e(shell_t *shell);
int backslash_t(shell_t *shell);
char *remove_caract(char *str);
int backslash_r(shell_t *shell);
int flags_e(shell_t *shell);
int alias_function(char **envp, shell_t *shell);
char *check_alias(char *line, shell_t *shell);
char *change_string(char *str, char *line, int j, int i);
int calc_len(char *str);
int check_input(shell_t *);
char *get_alias_path(shell_t *shell);
int unset_env(char **envp, shell_t *shell);
int print_e_flags(shell_t *shell, int j);
int flags_e_maj(shell_t *shell);
int flags_e_maj(shell_t *shell);
int backslash_v_f(shell_t *shell);
int check_separ(char *line, int i, int *value);
int is_end(char c);
char *get_env_line(char *line, char **env);

/*lib*/
char **add_letter_colon(char **array, int number, char *str, int i);
char **check_space_colon(char **array, int number, char **form);
int my_strlen_comma(char const *str);
int my_putchar(char c);
int my_str_isalpha_num(char const *str);
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
int my_strncmp_next(char const *s1, char const *s2, int n);
char *my_strcat_two(char *dest, char const *src);
int my_putstr_without_return(char const *str);
int my_strlen_env(char *str);
int my_strlen_egale(char const *str);
int my_strlen_pipe(char const *str);
char **my_str_to_world_array_comma(char *str);
char **check_space_comma(char **array, int number, char **form);
char **add_letter_comma(char **array, int number, char *str, int i);
char **str_to_wordtab(char const *, char const *);
int tab_len(char **);
char **clean_string(char **);
int my_strcmp(char const *s1, char const *s2);
void my_rev_list(cmd_t **);
void free_list(cmd_t *);
int my_strcmp_char(char const *s1, char const s2);
char *clean_str(char *);
int check_sep_function(list_t list, char *line, shell_t *shell, int i);
int my_strncmp_to_get_line(char *s1, char *s2, int n);

/*separator*/
cmd_t *parse_cmd(char *line);
separator_t find_separator(cmd_t *cmd, shell_t *shell);
int call_separator(char **envp, shell_t *shell, char *line, int x);
int do_double_and(char **envp, char *line, shell_t *shell, int x);
int do_double_or(char **envp, char *line, shell_t *shell, int x);
int is_double_or(char *line);
int my_separator_flags(char line, shell_t *shell);
int return_function(char **envp, char *line, shell_t *shell, int x);
int my_pattern_separator(char **envp, char *line, shell_t *shell,
char x, char path);
int is_or(char **envp, char *line, shell_t *shell, int x);
int check_time(char **env, char, char, shell_t *shell, int x);
int is_not_separator(char current, char plus_one, char minus_one);
int is_pipe(char, char, char);
char *which_sep(char current, char plus_one, char minus_one);
int check_invalid_command(cmd_t *);
int pipe_loop_ext(piping_t *piping, shell_t *shell, char **envp, pid_t pid);
int set_fd(piping_t *piping);

/*prompt user*/
void prompt_user(shell_t *shell);
char *get_username();
char *get_host();

typedef int (*flags)(shell_t *shell);
typedef int (*flags_separator)(char **envp, char *line, shell_t *shell, int x);
#endif /* !MY_H */
