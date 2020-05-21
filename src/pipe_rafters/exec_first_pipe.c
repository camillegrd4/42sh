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

void pipe_loop_ext(int fd_in, int *p, piping_t *piping, shell_t *shell)
{
    dup2(fd_in, 0);
    if (piping->next != NULL)
        dup2(p[1], 1);
    close(p[0]);
    shell->array = tabdup(piping->tab);
}

int loop_pipe(piping_t *piping, shell_t *shell, char **envp)
{
    int   p[2];
    pid_t pid;
    int   fd_in = 0;

    while (piping) {
        pipe(p);
        if ((pid = fork()) == -1)
            exit(EXIT_FAILURE);
        else if (pid == 0) {
            pipe_loop_ext(fd_in, p, piping, shell);
            if (exec_function(envp, shell, pid) == 84)
                return 84;
            exit(EXIT_FAILURE);
        } else {
            wait(NULL);
            close(p[1]);
            fd_in = p[0];
            piping = piping->next;
        }
    }
    return 0;
}

int exec_first_arg(char **envp, char *line, shell_t *shell, int x)
{
    char **array = str_to_wordtab(line, "|");

    array = clean_string(array);
    piping_t *piping = get_path(array);

    loop_pipe(piping, shell, envp);
    freetab(array);
    return 2;
}