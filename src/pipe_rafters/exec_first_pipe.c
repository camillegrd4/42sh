/*
** EPITECH PROJECT, 2020
** check
** File description:
** check
*/

#include "my.h"

piping_t *my_rev_pipe(piping_t *begin)
{
    piping_t *tmp = 0;
    piping_t *elem = begin;
    piping_t *next;

    while (elem->next) {
        next = elem->next;
        elem->next = tmp;
        tmp = elem;
        elem = next;
    }
    elem->next = tmp;
    return elem;
}

piping_t *add_element(piping_t *head, char *str)
{
    piping_t *tmp = malloc(sizeof(piping_t));
    int i = 0;

    if (!tmp)
        return NULL;
    tmp->tab = str_to_wordtab(str, " ");
    tmp->next = head;
    return tmp;
}

piping_t *get_path(char **tab)
{
    piping_t *head = NULL;
    int i = 0;

    while (tab[i]) {
        head = add_element(head, tab[i]);
        i++;
    }
    return (my_rev_pipe(head));
}

char **tabdup(char **tab)
{
    char **tmp;
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
    int   p[2];
    pid_t pid;
    int   fd_in = 0;

    while (piping) {
        pipe(p);
        if ((pid = fork()) == -1)
            exit(EXIT_FAILURE);
        else if (pid == 0) {
            dup2(fd_in, 0);
            if (piping->next != NULL)
                dup2(p[1], 1);
            close(p[0]);
            shell->array = tabdup(piping->tab);
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