##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## @Made by Math alias T1nt1n
##

SRC = 	sources/list/append.c \
		sources/list/free.c \
		sources/list/new.c \
		sources/list/remove.c \
		sources/node/free.c \
		sources/node/new.c \
		sources/node/unlink.c \
		sources/utils/is_number.c \
		sources/utils/malloc2.c \
		sources/champion/new.c \
		sources/champion/free.c \
		sources/champion/append_cmd.c \
		sources/cmd/new.c \
		sources/cmd/append_parameter.c \
		sources/cmd/free.c \
		sources/header/new.c \
		sources/header/free.c \

_TESTS =	../main.c \
			champion.c

SRC_OBJ = $(SRC:.c=.o)
INC = -I./includes

TESTSDIR = 		../../tests/criterion/$(NAME)/
TESTS =			$(addprefix $(TESTSDIR), $(_TESTS))
TESTS_OBJ = 	$(TESTS:.c=.o)
TESTS_CFLAGS =	-lcriterion --coverage

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
			@printf "$(STYLE_BLUE)📦 Compiling lib$(NAME) - $(BOLD_BLUE)\
[$<]$(STYLE_END)\n"
			@$(CC) $(INC) -c $< -o $@

clean:
			@rm -f $(SRC_OBJ)
			@rm -f $(TESTS_NAME)
			@rm -f $(TESTS_OBJ)

fclean: 	clean
			@rm -f lib$(NAME).a
			@rm -f ../lib$(NAME).a

re: 		fclean all

objects:		$(SRC_OBJ)

tests_objects:	$(TESTS_OBJ)

tests_criterion:
			@rm -f $(TESTS_OBJ) $(SRC_OBJ)
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
