##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

DEBUG =

LIB	=	lib

LIBDIR	=	./lib/my

SRC	=	src

SRCDIR	=	./src

TESTS = tests

TESTSDIR	=	./tests

all: $(LIB) $(SRC)

$(SRC):
ifeq ($(DEBUG),yes)
	$(MAKE) -C $(SRCDIR) DEBUG=yes
else
	$(MAKE) -C $(SRCDIR)
endif

$(LIB):
	$(MAKE) -C $(LIBDIR)

$(TESTS):
	$(MAKE) -C $(TESTSDIR)
#	gcc -o $(UNITS) $(SRC_UT) $(SRC) $(CFLAGS) $(LDFLAGS)

clean_src:
	$(MAKE) -C $(SRCDIR) clean

clean_lib:
	$(MAKE) -C $(LIBDIR) clean

clean: clean_lib clean_src

fclean_src:
	$(MAKE) -C $(SRC) fclean

fclean_lib:
	$(MAKE) -C $(LIBDIR) fclean

fclean: fclean_lib fclean_src


re: fclean all

.PHONY: all re clean clean_lib clean_src fclean fclean_lib fclean_src lib src
