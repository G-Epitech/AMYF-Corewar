##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## @Made by Math alias T1nt1n
##

SRC = my_put_nbr.c \
      my_putchar.c \
      my_putstr.c \
      my_strcmp.c \
      my_strcpy.c \
      my_strdup.c \
      my_strlen.c \
      my_strstr.c \
      error.c

OBJ = $(SRC:.c=.o)

NAME = my

COLOUR_GREEN=\033[0;32m

COLOUR_ORANGE=\033[0;33m

COLOUR_RED=\033[0;31m

COLOUR_BLUE=\033[0;34m

BOLD_BLUE=\033[1;34m

COLOUR_GREY=\033[0;30m

COLOUR_END=\033[0m

all: 		$(NAME)

$(NAME):	$(OBJ)
			@ar rc lib$(NAME).a $(OBJ)
			@cp lib$(NAME).a ../
%.o: %.c
			@printf "$(COLOUR_BLUE)📦 Compiling lib$(NAME) - $(BOLD_BLUE)\
[$<]$(COLOUR_END)\n"
			@gcc -c $< -o $@

clean:
			rm -f $(OBJ)

fclean: 	clean
			rm -f lib$(NAME).a
			rm -f ../lib$(NAME).a

re: 		fclean all
