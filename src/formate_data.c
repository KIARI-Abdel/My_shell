/*
** EPITECH PROJECT, 2017
** minishell2
** File description:
** mysh_formate_data
*/

#include "minishell.h"

int seek_end_line(char *line, int old)
{
    int  count = 0;
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == '"')
            count++;
    }
    if (old == 0) {
        if (count % 2 != 0)
            return (1);
        else
            return (0);
    } else {
        if (count % 2 == 0)
            return (1);
        else
            return (0);
    }
}

char *remove_newline(char *line)
{
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == '\n')
            line[i] = '\0';
        if (line[i] == '"')
            line[i] = ' ';
    }
    return (line);
}

char *formate_path(char *to_formate)
{
    char *res = NULL;
    int len = 0;

    while (to_formate[len] != '\0')
        len++;
    while (to_formate[len] != '/' && len != 0)
        len--;
    len++;
    res = malloc(sizeof(char) * (len + 1));
    for (int i = 0; i != len; i++)
        res[i] = to_formate[i];
    res[len] = '\0';
    return (res);
}