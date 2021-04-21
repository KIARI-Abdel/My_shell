/*
** EPITECH PROJECT, 2017
** minishell2
** File description:
** cd_retrieve_data
*/

#include "minishell.h"

char *get_old_path(env_var_t *env)
{
    env_var_t *browse = env;
    while (browse != NULL) {
        if (my_strncmp(browse->line, "OLDPWD", 6) == 0)
            return (browse->line);
        browse = browse->next;
    }
    return (NULL);
}

char *get_home_path(env_var_t *env)
{
    env_var_t *browse = env;
    while (browse != NULL) {
        if (my_strncmp(browse->line, "HOME", 4) == 0)
            return (browse->line);
        browse = browse->next;
    }
    return (NULL);
}

char *get_new_path(char *current_path)
{
    int i = 0;

    while (current_path[i] != '\0')
        i++;
    while (current_path[i] != '/' && i != 0)
        i--;
    current_path[i] = '\0';
    return (current_path);
}

int get_path_len(env_var_t *env)
{
    env_var_t *browse = env;
    int len = 0;
    while (browse != NULL) {
        len = my_strlen(browse->line);
        if (my_strncmp(browse->line, "PWD", 3) == 0)
            return (len);
        browse = browse->next;
    }
    return (0);
}

char *formate_oldpos(char *current_path)
{
    char *res = NULL;

    res = my_strcat(my_strdup("setenv "), my_strdup("OLDPWD "));
    res = my_strcat(res, current_path);
    return (res);
}