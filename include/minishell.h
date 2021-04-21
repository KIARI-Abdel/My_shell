/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** minishell
*/

#ifndef MINISHELL_H_
#define MINISHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include "my.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define IS_NUM(x) ((x <= '9' && x >= '0'))

typedef struct env_var
{
    char *line;
    struct env_var *next;
} env_var_t;

typedef struct minishell {
    char **copy_env;
    char *buffer;
    struct env_var *head;
} minishell_t;

typedef struct cmds {
    char *cmd;
    char **args;
    char *rred;
    char *wred;
    int pfd[2];
    struct cmds *next;
    struct cmds *prev;
} cmds_t;

// Mainc.c
env_var_t *add_first_elem(char *);
void add_element(env_var_t *, char *);
env_var_t *env_to_list(env_var_t *, char **);
minishell_t *env_to_tab(minishell_t *, char **);
int main(int, char **, char **);

// Manage_command.c


// Minishell.c
int check_next(char *, minishell_t *);
int  check_command(char *, minishell_t *);
char *complete_command(char *);
char *manage_arg(void);
int minishell(minishell_t *);


// Formate_data.c
char *remove_newline(char *);
int seek_end_line(char *, int);
char *formate_path(char *);

// Unsetenv_function.c
env_var_t *delete_element(env_var_t *, int);
int delete_env_var(char *, minishell_t *);

// Env_functions.c
int find_name(minishell_t *, char *);
char *formate_line(char *, char *);
int add_env_var(char *, minishell_t *);
int display_env(minishell_t *);

// Pwd_function.c
int pwd_function(minishell_t *);

// Cd_functions_next.c
int go_to_root(minishell_t *);
int go_level_up(minishell_t *);
int go_to_last(minishell_t *);
int go_to_path(minishell_t *, char *);

// Cd_function.c
int go_to_home(minishell_t *);
int cd_functio_next(char *, minishell_t *, char **, int);
int cd_function(char *, minishell_t *);

// Cd_retrieve_data.c
char *get_old_path(env_var_t *);
char *get_home_path(env_var_t *);
char *get_new_path(char *);
int get_path_len(env_var_t *);
char *formate_oldpos(char *);

// Little_functions.c
int is_number(char *);

// Little_functions_next.c
int my_put_nbr(int);
char *my_strdup(char *);
int  get_env_len(char **);


// My_str_to_wordtab.c
int get_word_nb(char *, char);
int get_line_size(char *, int, char);
char **my_str_to_wordtab(char *, char);
char *my_strcat(char *, char const *);
char *my_strcat_modif(char *, char const *, int);

// My_str_to_wordarray.c
int is_alpha_digit(char);
int pass_separator(char const *, int);
int count_separator(char const *);
int get_word_len(char const *, int);
char **my_str_to_wordarray(char const *);

// execute.c
void exec_cmds(cmds_t *list, char **env);

#endif /* !MINISHELL_H_ */
