##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

DEBUG =
ifeq ($(DEBUG),yes)
CFLAGS	=	-Iinclude -W -Wall -Wextra -g3
else
CFLAGS	=	-Iinclude -W -Wall -Wextra
endif

NAME	=	mysh

SRC	=	main.c					\
		little_functions.c			\
		little_functions_next.c			\
		env_functions.c				\
		minishell.c                     \
		my_str_to_wordarray.c           \
		formate_data.c                  \
		cd_function.c                   \
		unsetenv_function.c             \
		pwd_function.c                  \
		my_str_to_wordtab.c             \
		cd_functions_next.c             \
		cd_retrieve_data.c


OBJ	=	$(SRC:.c=.o)

LDFLAGS	=	-L../lib/my -lmy

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $@ $^ $(LDFLAGS)
	cp $@ ../

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re: fclean all

.PHONY: all clean fclean re rush3
