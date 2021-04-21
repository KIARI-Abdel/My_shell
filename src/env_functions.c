/*
** EPITECH PROJECT, 2017
** minishell2
** File description:
** env_functions
*/

#include "minishell.h"

int find_name(minishell_t *sh, char *name)
{
    int pos = 0;
    int len = 0;
    if (name != NULL)
        len = my_strlen(name);
    env_var_t *tmp = sh->head;
    while (tmp != NULL) {
        if (my_strncmp(tmp->line, name, (len - 1)) == 0)
            return (pos);
        pos++;
        tmp = tmp->next;
    }
    return (pos * (-1));
}

char *formate_line(char *name, char *val)
{
    int len = 0;
    if (name != NULL)
        len = my_strlen(name);
    if (val != NULL)
        len += my_strlen(val);
    len += 2;
    char *res = NULL;
    res = my_strcat(name, my_strdup("="));
    res = my_strcat(res, val);
    return (res);
}

int add_env_var(char *line, minishell_t *sh)
{
    env_var_t *browse = sh->head;
    char **command = my_str_to_wordtab(line, ' ');
    char *name = my_strdup(command[1]);
    char *val = my_strdup(command[2]);
    char *res = formate_line(name, val);
    int pos = find_name(sh, name);
    if (pos >= 0) {
        for (int j = 0; j != pos && browse->next != NULL; j++)
            browse = browse->next;
        browse->line = my_strdup(res);
    } else
        add_element(browse, res);
    return (0);
}

int display_env(minishell_t *sh)
{
    env_var_t *tmp = sh->head;
    while (tmp != NULL) {
        my_putstr(tmp->line);
        my_putchar('\n');
        tmp = tmp->next;
    }
    return (0);
}