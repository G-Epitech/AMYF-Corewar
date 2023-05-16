##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## @Made by Math alias T1nt1n
##

_SRC = 		asm.c \
			\
			parsing/parsing.c \
			parsing/header/header.c \
			parsing/body/body.c \
			parsing/file.c \
			\

SRCDIR =		sources/
SRC =			$(addprefix $(SRCDIR), $(_SRC))
SRC_COVER =		$(SRC:.c=.gcno)
SRC_PRFL =		$(SRC:.c=.gcda)

FTEST_REPO = https://github.com/Atomot/ftest/
FTEST_V = ftest-0.1.0-1.x86_64.rpm

CFLAGS += -Wall -Wextra -Werror -Wno-unused-command-line-argument -g
INC = -I./includes -I../lib
LDFLAGS = -L../lib -lcommon
OBJ = $(SRC:.c=.o)
PATH_COMMON = ../lib/common

NAME = asm

STYLE_GREEN=\033[0;32m
STYLE_ORANGE=\033[0;33m
STYLE_RED=\033[0;31m
STYLE_BLUE=\033[0;34m
STYLE_GREY=\033[0;30m
STYLE_BOLD=\033[1m
STYLE_END=\033[0m

COMPILING_O_LOG = "$(STYLE_BLUE)📑 Compiling sources -\
$(STYLE_BOLD)$(STYLE_BOLD)[%s]$(STYLE_END)\n"

.PHONY = all clean fclean re

$(NAME):	$(OBJ)
			@printf "$(STYLE_RED)🚚 Lib 'Common' Compilation...$(STYLE_END)\n"
			@make -C$(PATH_COMMON)
			@printf "$(STYLE_RED)🚚 Main Compilation...$(STYLE_END)\n"
			@gcc -o $(NAME) $(OBJ) $(LDFLAGS) $(INC)
			@printf "$(STYLE_GREEN)✅ Asm was successfully built\
			$(STYLE_END)\n"

%.o: 		%.c
			@printf $(COMPILING_O_LOG) $<
			@gcc $(LDFLAGS) $(CFLAGS) $(INC) -c $< -o $@

all: 		$(NAME)

clean:
			@rm -f $(NAME)
			@rm -f $(OBJ)
			@rm -f $(SRC_OBJ)
			@rm -f $(SRC_COVER)
			@make -C$(PATH_COMMON) clean -s

fclean: 	clean
			@make -C$(PATH_COMMON) fclean -s
			@printf "$(STYLE_ORANGE)🧽 Asm was successfully clean\
			$(STYLE_END)\n"

re: 		fclean all

style:		fclean
			@echo "$(STYLE_RED)🔍 Checking coding style...$(STYLE_END)"
			@coding-style . .
			@cat coding-style-reports.log

exec:		$(NAME)
			./$(NAME)

tests_ftest:
			echo "pass"

tests_custom:
			echo "pass"

tests_criterion:
			echo "pass"

tests_run:	tests_criterion

coverage:
				@gcovr

coverage_branch:
				@gcovr --branch
