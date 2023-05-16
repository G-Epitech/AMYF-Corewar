##
## EPITECH PROJECT, 2023
## corewar
## File description:
## Makefile
##

PATH_ASM = ./asm
PATH_COREWAR = ./corewar

FTEST_REPO = 	https://github.com/Atomot/ftest/
FTEST_V = 		ftest-0.1.0-1.x86_64.rpm

STYLE_GREEN=\033[0;32m
STYLE_ORANGE=\033[0;33m
STYLE_RED=\033[0;31m
STYLE_BLUE=\033[0;34m
STYLE_GREY=\033[0;30m
STYLE_BOLD=\033[1m
STYLE_END=\033[0m

NAME =			global_corewar

.PHONY: all clean fclean re

all: 			$(NAME)

$(NAME):
				@$(MAKE) -C $(PATH_ASM)
				# @$(MAKE) -C $(PATH_COREWAR)

docker:
				@docker run -it --rm -v $(shell pwd):/project -w /project \
				epitechcontent/epitest-docker tcsh

clean:
				@$(MAKE) -C $(PATH_ASM) clean
				# @$(MAKE) -C $(PATH_COREWAR) clean

fclean:
				@$(MAKE) -C $(PATH_ASM) fclean
				# @$(MAKE) -C $(PATH_COREWAR) fclean

re: 			fclean all

style:			fclean
				@printf "$(STYLE_RED)🔍 Checking coding style...$(STYLE_END)\n"
				@coding-style . .
				@cat coding-style-reports.log

tests_criterion:
				@$(MAKE) -C $(PATH_ASM) tests_criterion
				# @$(MAKE) -C $(PATH_COREWAR) tests_criterion

ftest:
				@echo "pass"

tests_custom:
				@echo "pass"

tests_run: 		tests_criterion

coverage:
				@gcovr

coverage_branch:
				@gcovr --branch
