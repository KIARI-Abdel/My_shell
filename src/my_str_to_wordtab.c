/*
** EPITECH PROJECT, 2018
** my_str_to_wordtab
** File description:
** minishell1
*/

#include "../include/my.h"

int get_word_nb(char *str, char c)
{
    int i = 0;
    int count = 1;

    while (str[i] != '\0') {
        if (str[i] == c && str[i + 1] != '\0')
            count++;
        i++;
    }
    return (count);
}

int get_line_size(char *str, int pos, char c)
{
    int count = 0;

    while (str[pos] != '\0' && str[pos] != c) {
        pos++;
        count++;
    }
    return (count);
}

char **my_str_to_wordtab(char *str, char c)
{
    int nb_line = get_word_nb(str, c);
    int i = 0;
    int j = 0;
    int k = 0;
    char **res = malloc(sizeof(char *) * (nb_line + 1));
    while (i != nb_line) {
        res[i] = malloc(sizeof(char) * (get_line_size(str, k, c) + 1));
        while (str[k] != c && str[k] != '\0') {
            res[i][j] = str[k];
            j++;
            k++;
        }
        res[i][j] = '\0';
        j = 0;
        i++;
        k++;
    }
    res[i] = NULL;
    return (res);
}
