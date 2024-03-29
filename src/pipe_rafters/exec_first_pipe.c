/*
** EPITECH PROJECT, 2020
** check
** File description:
** check
*/

#include "my.h"

char **tabdup(char **tab)
{
    char **tmp = NULL;
    int	i = 0;

    if (tab == NULL)
        return NULL;
    if ((tmp = malloc(sizeof(char *) * (tab_len(tab) + 2))) == NULL)
        return (NULL);
    if (tab == NULL) {
        if ((tmp[0] = strdup("")) == NULL)
            return (NULL);
        tmp[1] = NULL;
        return (tmp);
    }
    while (tab[i]) {
        if ((tmp[i] = strdup(tab[i])) == NULL)
            return (NULL);
        ++i;
    }
    tmp[i] = NULL;
    return (tmp);
}

void freetab(char **tab)
{
    int i = 0;

    while (tab[i])
        free(tab[i++]);
}

int loop_pipe(piping_t *piping, shell_t *shell, char **envp)
{
    pid_t pid;
    int status = 0;

    shell->array = tabdup(piping->tab);
    if (!piping->next && find_recode_function(shell->array[0], shell)) {
        pipe_loop_ext(piping, shell, envp, -1);
    } else {
        if ((pid = fork()) == -1) {
            exit(EXIT_FAILURE);
        } else if (pid == 0)
            return (pipe_loop_ext(piping, shell, envp, pid));
    }
    if (isatty(piping->fd[1]) == 0)
        close(piping->fd[1]);
    if (isatty(piping->fd[0]) == 0)
        close(piping->fd[0]);
    piping = piping->next;
    if (piping != NULL)
        loop_pipe(piping, shell, envp);
    waitpid(pid, &status, 0);
    return 0;
}

int check_pipe_erro(char *line, int i)
{
    if (line[i] == '|') {
        if (!(line[i - 1])) {
            printf("Invalid null command\n");
            return 1;
        }
        if (!(line[i + 1])) {
            printf("Invalid null command\n");
            return 1;
        }
    }
    return 0;
}

int exec_first_arg(char **envp, char *line, shell_t *shell, int x)
{
    char *test = my_strdup(clean_str(line));
    char **array = str_to_wordtab(line, "|");
    piping_t *piping = NULL;
    int i = 0;

    array = clean_string(array);
    while (test[i]) {
        if (check_pipe_erro(test, i) == 1)
            return 1;
        i++;
    }
    piping = get_path(array);
    set_fd(piping);
    loop_pipe(piping, shell, envp);
    freetab(array);
    return 2;
}