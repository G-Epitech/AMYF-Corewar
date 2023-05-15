##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## @Made by Math alias T1nt1n
##

SRC = 		sources/asm.c

NAME = asm

FTEST_REPO = https://github.com/Atomot/ftest/

FTEST_V = ftest-0.1.0-1.x86_64.rpm

CFLAGS += -Wall -Wextra -Werror -Wno-unused-command-line-argument -g

INC = -I./include -I../lib

LDFLAGS = -L../lib -lcommon

OBJ = $(SRC:.c=.o)

PATH_COMMON = ../lib/common

COLOUR_GREEN=\033[0;32m

COLOUR_ORANGE=\033[0;33m

COLOUR_RED=\033[0;31m

COLOUR_BLUE=\033[0;34m

COLOUR_GREY=\033[0;30m

COLOUR_END=\033[0m


$(NAME):	$(OBJ)
			@printf "$(COLOUR_RED)🚚 Lib 'Common' compliation...$(COLOUR_END)\n"
			@make -C$(PATH_COMMON)
			@printf "$(COLOUR_RED)🚚 Main compliation...$(COLOUR_END)\n"
			@gcc -o $(NAME) $(OBJ) $(LDFLAGS) $(INC)
			@printf "$(COLOUR_GREEN)✅ Asm was successfully built\
			$(COLOUR_END)\n"

%.o: 		%.c
			@printf "$(COLOUR_BLUE)📑 Compiling $(BOLD_BLUE)[$<]$(COLOUR_END)\n"
			@gcc $(LDFLAGS) $(CFLAGS) $(INC) -c $< -o $@

all: 		$(NAME)

clean:
			@rm -f $(NAME)
			@rm -f $(OBJ)
			@make -C$(PATH_COMMON) clean -s

fclean: 	clean
			@make -C$(PATH_COMMON) fclean -s
			@printf "$(COLOUR_ORANGE)🧽 Asm was successfully clean\
			$(COLOUR_END)\n"

re: 		fclean all

style:		fclean
			@echo "$(COLOUR_RED)🔍 Checking coding style...$(COLOUR_END)"
			@coding-style . .
			@cat coding-style-reports.log

exec:		$(NAME)
			./$(NAME)

tests_run:
			echo "pass"

criterion:
			echo "pass"

ftest:
			echo "pass"

custom:
			echo "pass"

.PHONY = all clean fclean re
