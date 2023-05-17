##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## @Made by Math alias T1nt1n
##

_SRC = 		list/append.c \
			list/free.c \
			list/new.c \
			list/remove.c \
			node/free.c \
			node/new.c \
			node/unlink.c \
			utils/is_number.c \
			utils/malloc2.c \
			champion/new.c \
			champion/free.c \
			champion/append_cmd.c \
			cmd/new.c \
			cmd/append_parameter.c \
			cmd/free.c \
			header/new.c \
			header/free.c \

_TESTS =	../main.c \
			champion.c

SRCDIR =		sources/
SRC =			$(addprefix $(SRCDIR), $(_SRC))
SRC_OBJ = 		$(SRC:.c=.o)
SRC_COVER =		$(SRC:.c=.gcno)
SRC_PRFL =		$(SRC:.c=.gcda)

TESTSDIR = 		../../tests/criterion/$(NAME)/
TESTS =			$(addprefix $(TESTSDIR), $(_TESTS))
TESTS_OBJ = 	$(TESTS:.c=.o)
TESTS_CFLAGS =	-lcriterion --coverage

INC = 			-I./includes

NAME = common
TESTS_NAME = common_tests

STYLE_GREEN=\033[0;32m
STYLE_ORANGE=\033[0;33m
STYLE_RED=\033[0;31m
STYLE_BLUE=\033[0;34m
STYLE_GREY=\033[0;30m
STYLE_BOLD=\033[1m
STYLE_END=\033[0m

.PHONY: all clean fclean re

all: 		$(NAME)

$(NAME):	$(SRC_OBJ)
			@ar rc lib$(NAME).a $(SRC_OBJ) $(CFLAGS)
			@cp lib$(NAME).a ../

%.o: %.c
			@rm -rf $(<:.c=.gcda) $(<:.c=.gcno)
			@printf "$(STYLE_BLUE)📦 Compiling lib$(NAME) - $(BOLD_BLUE)\
[$<]$(STYLE_END)\n"
			@$(CC) $(INC) $(CFLAGS) -c $< -o $@

clean:
			@rm -f $(SRC_OBJ)
			@rm -f $(SRC_COVER) $(SRC_PRFL)
			@rm -f $(TESTS_NAME)
			@rm -f $(TESTS_OBJ)

fclean: 	clean
			@rm -f lib$(NAME).a
			@rm -f ../lib$(NAME).a

re: 		fclean all

objects:		$(SRC_OBJ)

tests_objects:	$(TESTS_OBJ)

tests_criterion:
			@printf "$(STYLE_RED)🧪 Tests compilation...$(STYLE_END)\n"
			@$(MAKE) objects CFLAGS+=--coverage -s
			@$(MAKE) tests_objects -s
			@$(CC) -o $(TESTS_NAME) $(SRC_OBJ) $(TESTS_OBJ) \
			$(LDFLAGS) $(CFLAGS) $(INC) $(TESTS_CFLAGS)
			@printf "$(STYLE_GREEN)✅ Tests were successfully built\
			$(STYLE_END)\n"
			@./$(TESTS_NAME)

tests_run:	tests_criterion

coverage:
			@gcovr

coverage_branch:
			@gcovr --branch
