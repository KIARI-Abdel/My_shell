/*
** EPITECH PROJECT, 2017
** minishell2
** File description:
** unsetenv_functions
*/

#include "minishell.h"

env_var_t *delete_element(env_var_t *head, int pos)
{
    env_var_t *browse = head;
    env_var_t *ret = browse;
    env_var_t *to_delete;
    for (int i = 0; i < (pos - 1) && browse != NULL; i++)
        browse = browse->next;
    to_delete = browse->next;
    browse->next = browse->next->next;
    free(to_delete);
    return (ret);
}

int delete_env_var(char *line, minishell_t *sh)
{
    char **command = my_str_to_wordarray(line);
    char *name = my_strdup(command[1]);
    int pos = find_name(sh, name);
    if (pos >= 0)
        sh->head = delete_element(sh->head, pos);
    return (0);
}