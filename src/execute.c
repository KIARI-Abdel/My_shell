/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** execute
*/

#include "minishell.h"

static void read_red(cmds_t *list)
{
    char *tmp = NULL;
    char *gnl = NULL;
    int fd;
    size_t st = 0;

    if (list->rred[1] == ' ') {
        fd = open(list->rred + 2, O_RDONLY);
        dup2(fd, 0);
        return;
    } else {
        tmp = malloc(sizeof(char));
        tmp[0] = 0;
        write(1, "? ", 2);
        for (; getline(&gnl, &st, stdin) > 0 || my_strcmp(gnl, list->rred + 3);
                tmp = my_append_str(tmp, gnl), gnl = NULL, st = 0)
            write(1, "? ", 2);
        free(gnl);
        write(0, tmp, my_strlen(tmp));
        free(tmp);
    }
}

static void write_red(cmds_t *list)
{
    int tfd;
    char *tmp;

    for (tmp = list->wred; *tmp == '>' || *tmp == ' '; tmp++);
    tfd = open(tmp, ((list->wred[1] == '>') ? O_WRONLY | O_APPEND : O_WRONLY));
    dup2(tfd, 1);
}

static void exec_rec(cmds_t *list, char **env)
{
    if (list->next != NULL && list->next->next != NULL && list->next->next->rred != NULL && list->next->next->rred[0] == "|") {
        close(list->next->next->pfd[0]);
        close(list->next->next->pfd[1]);
    }
    if (list->rred != NULL && list->rred[0] == '|')
        pipe(list->pfd);
    if (fork() == 0) {
        if (list->wred != NULL && list->wred[0] == '|') {
            close(list->pfd[0]);
            dup2(list->pfd[1], 1);
        } else
            write_red(list);
        if (list->rred != NULL && list->rred[0] == '|') {
            dup2(list->prev->pfd[0], 0);
            close(list->prev->pfd[1]);
        } else
            read_red(list);
        execve(list->cmd, list->args, env);
    }
    (list->rred != NULL && list->rred[0] == '|') ? exec_rec(list->prev, env) :0;
}

void exec_cmds(cmds_t *list, char **env)
{
    cmds_t *tmp = list;

    for (; tmp != NULL && tmp->wred && !my_strncmp(tmp->wred, "|", 1);
            tmp = tmp->next);
    if (tmp != list)
        exec_rec(tmp, env);
    else if (fork() == 0) {
        if (list->rred != NULL)
            read_red(list);
        if (list->wred != NULL)
            write_red(list);
        execve(list->cmd, list->args, env);
    }
    wait(NULL);
    for (size_t i = 0; list->wred != NULL && list->wred[0] == '|' && i < 2;
        i++, list = list->next) {
        close(list->pfd[0]);
        close(list->pfd[1]);
    }
    return (tmp);
}
