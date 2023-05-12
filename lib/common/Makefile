##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## @Made by Math alias T1nt1n
##

SRC = 	list/append.c \
		list/free.c \
		list/new.c \
		list/remove.c \
		node/free.c \
		node/new.c \
		node/unlink.c \
		utils/asprintf2.c \
		utils/is_number.c \
		utils/malloc2.c \

OBJ = $(SRC:.c=.o)

INC = -I./include

NAME = common

COLOUR_GREEN=\033[0;32m

COLOUR_ORANGE=\033[0;33m

COLOUR_RED=\033[0;31m

COLOUR_BLUE=\033[0;34m

BOLD_BLUE=\033[1;34m

COLOUR_GREY=\033[0;30m

COLOUR_END=\033[0m

.PHONY: all clean fclean re

all: 		$(NAME)

$(NAME):	$(OBJ)
			@ar rc lib$(NAME).a $(OBJ) $(CFLAGS)
			@cp lib$(NAME).a ../
%.o: %.c
			@printf "$(COLOUR_BLUE)📦 Compiling lib$(NAME) - $(BOLD_BLUE)\
[$<]$(COLOUR_END)\n"
			@gcc $(INC) -c $< -o $@

clean:
			rm -f $(OBJ)

fclean: 	clean
			rm -f lib$(NAME).a
			rm -f ../lib$(NAME).a

re: 		fclean all
