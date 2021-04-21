/*
** EPITECH PROJECT, 2017
** minishell2
** File description:
** pwd_function
*/

#include "minishell.h"

int pwd_function(minishell_t *sh)
{
    char *path = NULL;
    int len = get_path_len(sh->head);
    path = getcwd(path, len);
    my_putstr(path);
    my_putchar('\n');
    return (0);
}