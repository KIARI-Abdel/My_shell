/*
** EPITECH PROJECT, 2019
** my_str_to_word_array
** File description:
** task04
*/

#include "minishell.h"

int is_alpha_digit(char c)
{
    int check = 1;
    if (c <= 'z' && c >= 'a')
        check = 0;
    else if ((c <= 'Z' && c >= 'A') || (c <= '9' && c >= '0'))
        check = 0;
    return (check);
}

int pass_separator(char const *str, int i)
{
    if (is_alpha_digit(str[i]) == 1) {
        while (is_alpha_digit(str[i]) == 1 && str[i] != '\0')
            i++;
    }
    return (i);
}

int count_separator(char const *str)
{
    int i = 0;
    int count = 1;
    i = pass_separator(str, i);
    if (str[i] == '\0' && str[i + 1] == '\0')
            return (count);
    while (str[i] != '\0') {
        if (is_alpha_digit(str[i]) == 1 && str[i + 1] != '\0') {
                count++;
                i = pass_separator(str, i);
        }
        i++;
    }
    return (count);
}

int get_word_len(char const *str, int i)
{
    int count = 0;
    i = pass_separator(str, i);
    while (is_alpha_digit(str[i]) == 0 && str[i] != '\0' && str[i] != ' ') {
        count++;
        i++;
    }
    return (count);
}

char **my_str_to_wordarray(char const *str)
{
    int sep = count_separator(str);
    int len = get_word_len(str, 0);
    int k = 0;
    char **res = malloc(sizeof(char *) * (sep + 1));
    for (int i = 0; i < sep; i++) {
        k = pass_separator(str, k);
        len = get_word_len(str, k);
        res[i] = malloc(sizeof(char) * (len + 1));
        for (int j = 0; j < len && str[k] != '\0'; j++) {
            res[i][j] = str[k];
            k++;
        }
        res[i][len] = '\0';
    }
    res[sep] = NULL;
    return (res);
}
