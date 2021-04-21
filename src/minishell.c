/*
** EPITECH PROJECT, 2017
** minishell2
** File description:
** mysh
*/

#include "minishell.h"

int check_next(char *line, minishell_t *sh)
{
    int i = 0;
    while (line[i] == ' ')
        i++;
    if (my_strncmp(&line[i], "unsetenv", 8) == 0)
        delete_env_var(line, sh);
    else if (my_strncmp(&line[i], "cd", 2) == 0)
        cd_function(line, sh);
    else if (my_strncmp(&line[i], "pwd", 3) == 0)
        pwd_function(sh);
    return (0);
}

int check_command(char *line, minishell_t *sh)
{
    int check = 0;
    int i = 0;
    while (line[i] == ' ')
        i++;
    if (my_strncmp(&line[i], "exit", 4) == 0)
        check = -1;
    else if (my_strncmp(&line[i], "env", 3) == 0)
        display_env(sh);
    else if (my_strncmp(&line[i], "setenv", 6) == 0)
        add_env_var(line, sh);
    check_next(line, sh);
    return (check);
}

char *complete_command(char *line)
{
    size_t len = 0;
    ssize_t nread;
    char *tmp = my_strdup(line);
    int check = 1;
    while (1) {
        my_putchar('?');
        nread = getline(&line, &len, stdin);
        if (nread == -1)
            my_puterr("Invalid command\n");
        check = seek_end_line(line, check);
        tmp = remove_newline(tmp);
        line = remove_newline(line);
        tmp = my_strcat(tmp, line);
        if (check == 0)
            return (tmp);
    }
}

char *manage_arg(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    nread = getline(&line, &len, stdin);
    if (nread == -1)
        my_puterr("Invalid command\n");
    if (seek_end_line(line, 0) == 1)
        line = complete_command(line);
    return (line);
}

int minishell(minishell_t *sh)
{
    char *line = NULL;
    int check = 0;
    while (1) {
        my_putchar('>');
        line = manage_arg();
        check = check_command(line, sh);
        if (check == -1)
            return (0);
    }
}
