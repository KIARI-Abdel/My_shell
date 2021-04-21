/*
** EPITECH PROJECT, 2017
** minishell2
** File description:
** cd_function
*/

#include "minishell.h"

int go_to_home(minishell_t *sh)
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
    current_path = getcwd(current_path, len);
    if (chdir(&home_path[i]) == 0) {
        oldpwd = formate_oldpos(current_path);
        add_env_var(oldpwd, sh);
    }
    return (0);
}

int cd_function_next(char *line, minishell_t *sh, char **command, int check)
{
    if (my_strncmp(command[1], "~", 1) == 0)
        go_to_home(sh);
    else if (my_strncmp(command[1], "-", 1) == 0)
        check = go_to_last(sh);
    if (check != 0)
        go_to_path(sh, line);
    return (0);
}

int cd_function(char *line, minishell_t *sh)
{
    char **command = my_str_to_wordtab(line, ' ');
    int check = 1;
    if (command[1] == NULL)
        check = go_to_home(sh);
    else if (command[1] != NULL) {
        if (my_strncmp(command[1], "/", 1) == 0 && my_strlen(command[1]) == 2)
            check = go_to_root(sh);
        if (my_strncmp(command[1], "..", 2) == 0) {
            check = go_level_up(sh);
        }
        cd_function_next(line, sh, command, check);
    }
    return (0);
}