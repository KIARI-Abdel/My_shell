/*
** EPITECH PROJECT, 2017
** minishell2
** File description:
** cd_functions_next
*/

#include "minishell.h"

int go_to_root(minishell_t *sh)
{
    char *home_path = get_home_path(sh->head);
    int len = get_path_len(sh->head);
    char *current_path = NULL;
    char *oldpwd = NULL;
    int i = 0;
    while (home_path[i] != '=' && home_path[i] != '\0')
        i++;
    if (home_path[i + 1] != '\0')
        i++;
    char **tmp = my_str_to_wordtab(&home_path[i], '/');
    char *root = NULL;
    root = my_strcat(my_strdup("/"), tmp[1]);
    current_path = getcwd(current_path, len);
    if (chdir(root) == 0) {
        oldpwd = formate_oldpos(current_path);
        add_env_var(oldpwd, sh);
    }
    return (0);
}

int go_level_up(minishell_t *sh)
{
    char *current_path = NULL;
    int len = get_path_len(sh->head);
    char *new_path = NULL;
    char *oldpwd = NULL;
    current_path = getcwd(current_path, len);
    oldpwd = my_strdup(current_path);
    new_path = get_new_path(current_path);
    if (chdir(new_path) == 0) {
        oldpwd = formate_oldpos(oldpwd);
        add_env_var(oldpwd, sh);
    }
    return (0);
}

int go_to_last(minishell_t *sh)
{
    char *path = get_old_path(sh->head);
    int len = get_path_len(sh->head);
    char *current = NULL;
    int i = 0;
    if (path == NULL)
        return (0);
    while (path[i] != '=' && path[i] != '\0')
        i++;
    i++;
    current = getcwd(current, len);
    if (chdir(&path[i]) == 0) {
        current = formate_oldpos(current);
        add_env_var(current, sh);
    }
    return (0);
}

int go_to_path(minishell_t *sh, char *line)
{
    char **cd = my_str_to_wordtab(line, ' ');
    char *current = NULL;
    char *old = NULL;
    int len = get_path_len(sh->head);
    int check = 0;
    char *path = NULL;
    current = getcwd(current, len);
    if (cd[1] == NULL)
        return (0);
    path = formate_path(cd[1]);
    check = chdir(path);
    if  (check == 0) {
        old = formate_oldpos(current);
        add_env_var(old, sh);
    }
    return (0);
}