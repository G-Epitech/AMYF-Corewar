##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## @Made by Math alias T1nt1n
##

_SRC = 		arena/init.c \
			arena/utils.c \
			\
			parsing/parsing.c \
			parsing/file.c \
			parsing/header.c \
			parsing/utils/read.c \
			parsing/utils/display.c \
			parsing/body/body.c \
			parsing/body/param.c \
			\
			utils/new.c \
			utils/sort.c \
			utils/free.c \

_TESTS =	../main.c \
			parsing.c \

SRCDIR =		sources/
SRC =			$(addprefix $(SRCDIR), $(_SRC))
MAIN =			$(addprefix $(SRCDIR), $(NAME).c)
MAIN_OBJ =		$(MAIN:.c=.o)
SRC_OBJ = 		$(SRC:.c=.o)

SRC_COVER =		$(SRC:.c=.gcno)
SRC_PRFL =		$(SRC:.c=.gcda)

override CFLAGS += -Wall -Wextra -Werror -Wno-unused-command-line-argument -g
INC = -I./includes -I../lib
LDFLAGS = -L../lib -lcommon -lmy
PATH_COMMON = ../lib/common
PATH_MY = ../lib/my

TESTSDIR = 		../tests/criterion/$(NAME)/
TESTS =			$(addprefix $(TESTSDIR), $(_TESTS))
TESTS_OBJ = 	$(TESTS:.c=.o)
TESTS_CFLAGS =	-lcriterion --coverage

NAME = corewar
TESTS_NAME = corewar_tests

STYLE_GREEN=\033[0;32m
STYLE_ORANGE=\033[0;33m
STYLE_RED=\033[0;31m
STYLE_BLUE=\033[0;34m
STYLE_GREY=\033[0;30m
STYLE_BOLD=\033[1m
STYLE_END=\033[0m

COMPILING_O_LOG = "$(STYLE_BLUE)📑 Compiling sources -\
$(STYLE_BOLD)$(STYLE_BOLD)[%s]$(STYLE_END)\n"
TESTS_LOG = "$(STYLE_GREEN)✅ Tests for '%s' were \
successfully built $(STYLE_END)\n"

.PHONY = all clean fclean re

$(NAME):	$(SRC_OBJ) $(MAIN_OBJ)
			@printf "$(STYLE_RED)🚚 Lib 'Common' Compilation...$(STYLE_END)\n"
			@make -C $(PATH_COMMON) -s
			@printf "$(STYLE_RED)🚚 Lib 'My' Compilation...$(STYLE_END)\n"
			@make -C $(PATH_MY) -s
			@printf "$(STYLE_RED)🚚 Main Compilation...$(STYLE_END)\n"
			@$(CC) -o $(NAME) $(SRC_OBJ) $(MAIN_OBJ) $(CFLAGS) $(LDFLAGS)\
			$(INC)
			@printf "$(STYLE_GREEN)✅ Corewar was successfully built\
			$(STYLE_END)\n"

%.o: 		%.c
			@rm -rf $(<:.c=.gcda) $(<:.c=.gcno)
			@printf $(COMPILING_O_LOG) $<
			@$(CC) $(LDFLAGS) $(CFLAGS) $(INC) -c $< -o $@

all: 		$(NAME)

clean:
			@rm -f $(NAME)
			@rm -f $(TESTS_NAME)
			@rm -f $(SRC_OBJ)
			@rm -f $(MAIN_OBJ)
			@rm -f $(SRC_COVER) $(SRC_PRFL)
			@rm -f $(TESTS_OBJ)
			@make -C $(PATH_COMMON) clean -s
			@make -C $(PATH_MY) clean -s

fclean: 	clean
			@make -C $(PATH_COMMON) fclean -s
			@make -C $(PATH_MY) fclean -s
			@printf "$(STYLE_ORANGE)🧽 Corewar was successfully clean\
			$(STYLE_END)\n"

re: 		fclean all

style:		fclean
			@echo "$(STYLE_RED)🔍 Checking coding style...$(STYLE_END)"
			@coding-style . .
			@cat coding-style-reports.log

exec:		$(NAME)
			./$(NAME)

objects:		$(SRC_OBJ)

tests_objects:	$(TESTS_OBJ)

tests_ftest:
			echo "pass"

tests_custom:
			echo "pass"

tests_criterion:
			@rm -f $(TESTS_OBJ) $(SRC_OBJ)
			@$(MAKE) -C $(PATH_MY) -s
			@$(MAKE) -C $(PATH_COMMON) -s
			@printf "$(STYLE_RED)🧪 Tests compilation...$(STYLE_END)\n"
			@$(MAKE) objects CFLAGS+=--coverage -s
			@$(MAKE) tests_objects -s
			@$(CC) -o $(TESTS_NAME) $(SRC_OBJ) $(TESTS_OBJ) \
			$(LDFLAGS) $(CFLAGS) $(INC) $(TESTS_CFLAGS)
			@printf $(TESTS_LOG) $(NAME)
			@./$(TESTS_NAME)

tests_run:	tests_criterion

coverage:
				@gcovr

coverage_branch:
				@gcovr --branch
