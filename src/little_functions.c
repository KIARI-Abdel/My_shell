/*
** EPITECH PROJECT, 2018
** mysh
** File description:
** little_functions
*/

#include "minishell.h"

int is_number(char *str)
{
    int check = 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (IS_NUM(str[i]) == 1 && str[i] != ' ')
            check = -1;
    }
    return (check);
}

int my_strcmp(char const *s1, char const *s2)
{
    for (int i = 0;; i++) {
        if (s1[i] < s2[i])
            return (-1);
        else if (s1[i] > s2[i])
            return (1);
        if (s1[i] == '\0' || s2[i] == '\0')
            break;
    }
    return (0);
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    for (int i = 0; i != n; i++) {
        if (s1[i] < s2[i])
            return (-1);
        else if (s1[i] > s2[i])
            return (1);
        if (s1[i] == '\0' || s2[i] == '\0')
            break;
    }
    return (0);
}

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int len = my_strlen(dest) + my_strlen(src);
    char *res = malloc(sizeof(char) * (len + 2));
    if (dest != NULL) {
        for (i = 0; dest[i] != '\0'; i++)
            res[i] = dest[i];
    }
    if (src != NULL) {
        for (int j = 0; src[j] != '\0'; j++) {
            res[i] = src[j];
            i++;
        }
    }
    res[i] = '\0';
    return (res);
}