/*
** EPITECH PROJECT, 2017
** minishell2
** File description:
** main
*/

#include "minishell.h"

env_var_t *add_first_elem(char *actual)
{
    env_var_t *list = malloc(sizeof(env_var_t));
    list->line = my_strdup(actual);
    list->next = NULL;
    return (list);
}

void add_element(env_var_t *head, char *actual)
{
    env_var_t *elem = malloc(sizeof(env_var_t));
    env_var_t *tmp = head;
    elem->line = my_strdup(actual);
    elem->next = NULL;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = elem;
}

env_var_t *env_to_list(env_var_t *env, char **envp)
{
    for (int i = 0; envp[i] != NULL; i++) {
        if (env == NULL)
            env = add_first_elem(envp[i]);
        else
            add_element(env, envp[i]);
    }
    return (env);
}

minishell_t *env_to_tab(minishell_t *sh, char **envp)
{
    int len = get_env_len(envp);
    int i = 0;

    sh->copy_env = malloc(sizeof(char *) * (len + 1));
    while (envp[i] != NULL) {
        sh->copy_env[i] = my_strdup(envp[i]);
        i++;
    }
    sh->copy_env[i] = NULL;
    return (sh);
}

int main(int ac, char **av, char **envp)
{
    (void)av;
    minishell_t *sh = malloc(sizeof(minishell_t));
    env_var_t *env = NULL;
    if (ac > 1) {
        my_puterr("No arguments needed to run mysh\n");
        return (84);
    }
    env = env_to_list(env, envp);
    sh->head = env;
    sh = env_to_tab(sh, envp);
    minishell(sh);
    return (0);
}
