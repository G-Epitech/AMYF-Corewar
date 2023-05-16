##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## @Made by Math alias T1nt1n
##

SRC = 	source/list/append.c \
		source/list/free.c \
		source/list/new.c \
		source/list/remove.c \
		source/node/free.c \
		source/node/new.c \
		source/node/unlink.c \
		source/utils/asprintf2.c \
		source/utils/is_number.c \
		source/utils/malloc2.c \
		source/champion/new.c \
		source/champion/free.c \
		source/champion/append_cmd.c \
		source/cmd/new.c \
		source/cmd/append_parameter.c \
		source/cmd/free.c \
		source/header/new.c \
		source/header/free.c \

_TESTS =	criterion/main.c

OBJ = $(SRC:.c=.o)
INC = -I./include

TESTSDIR = 		tests/
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

$(NAME):	$(OBJ)
			@ar rc lib$(NAME).a $(OBJ) $(CFLAGS)
			@cp lib$(NAME).a ../
%.o: %.c
			@printf "$(STYLE_BLUE)📦 Compiling lib$(NAME) - $(BOLD_BLUE)\
[$<]$(STYLE_END)\n"
			@gcc $(INC) -c $< -o $@

clean:
			rm -f $(OBJ)
			@rm -f $(TESTS_OBJ)

fclean: 	clean
			rm -f lib$(NAME).a
			rm -f ../lib$(NAME).a

re: 		fclean all

objects:		$(SRC_OBJ)

tests_objects:	$(TESTS_OBJ)

tests_criterion:
			@rm -f $(TESTS_OBJ)
			@printf "$(STYLE_RED)🧪 Tests compliation...$(STYLE_END)\n"
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
