##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## @Made by Math alias T1nt1n
##

SRC = my_put_nbr.c \
      my_putchar.c \
      my_putstr.c \
      my_printf.c \
      my_strcmp.c \
      my_strcpy.c \
      my_strdup.c \
      my_strlen.c \
      my_strstr.c \
      str_to_word_array.c \
      my_strconcat.c \
      free_str_tab.c \
      my_memset.c \
      my_getnbr.c \
      my_str_isnum.c \
      my_write_big_endian.c \
      error.c

OBJ = $(SRC:.c=.o)

NAME = my

STYLE_GREEN=\033[0;32m
STYLE_ORANGE=\033[0;33m
STYLE_RED=\033[0;31m
STYLE_BLUE=\033[0;34m
STYLE_GREY=\033[0;30m
STYLE_BOLD=\033[1m
STYLE_END=\033[0m

COMPILING_O_LOG = "$(STYLE_BLUE)📦 Compiling lib$(NAME) -\
$(STYLE_BOLD)$(STYLE_BOLD)[%s]$(STYLE_END)\n"

all: 		$(NAME)

$(NAME):	$(OBJ)
			@ar rc lib$(NAME).a $(OBJ)
			@mv lib$(NAME).a ../lib$(NAME).a
%.o: %.c
			@printf $(COMPILING_O_LOG) $<
			@gcc -c $< -o $@

clean:
			rm -f $(OBJ)

fclean: 	clean
			rm -f ../lib$(NAME).a

re: 		fclean all
