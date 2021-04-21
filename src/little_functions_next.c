/*
** EPITECH PROJECT, 2018
** my_pushswap
** File description:
** little_functions_next
*/

#include "minishell.h"

int my_put_nbr(int nb)
{
    int div = 1;
    unsigned int res = 0;

    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    res = nb;
    while ((res / div) >= 10)
        div *= 10;
    while ( div > 0) {
        my_putchar((res / div) % 10 + '0');
        div /= 10;
    }
    return (0);
}

char *my_strdup(char *src)
{
    int len = my_strlen(src);
    char *res = malloc(sizeof(char) * (len + 1));
    int i = 0;

    while (src[i] != '\0') {
        res[i] = src[i];
        i++;
    }
    res[i] = '\0';
    return (res);
}

int get_env_len(char **envp)
{
    int i = 0;

    while (envp[i] != NULL)
        i++;
    return (i);
}
