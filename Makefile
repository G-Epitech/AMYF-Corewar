##
## EPITECH PROJECT, 2023
## corewar
## File description:
## Makefile
##

PATH_ASM = ./asm
PATH_COREWAR = ./corewar
PATH_COMMON = ./lib/common

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
				@printf "$(STYLE_RED)🚚 Lib 'Common' Compilation...\
				$(STYLE_END)\n"
				@$(MAKE) -C $(PATH_COMMON) -s
				@printf "$(STYLE_RED)\n🚚 Project 'Asm' Compilation...\
				$(STYLE_END)\n"
				@$(MAKE) -C $(PATH_ASM) -s
				@printf "$(STYLE_RED)\n🚚 Project 'Corewar' Compilation...\
				$(STYLE_END)\n"
				@$(MAKE) -C $(PATH_COREWAR) -s

docker:
				@docker run -it --rm -v $(shell pwd):/project -w /project \
				epitechcontent/epitest-docker tcsh

clean:
				@$(MAKE) -C $(PATH_ASM) clean
				@$(MAKE) -C $(PATH_COREWAR) clean

fclean:
				@$(MAKE) -C $(PATH_ASM) fclean
				@$(MAKE) -C $(PATH_COREWAR) fclean

re:
				@$(MAKE) all

style:			fclean
				@printf "$(STYLE_RED)🔍 Checking coding style...$(STYLE_END)\n"
				@coding-style . .
				@cat coding-style-reports.log

tests_criterion:
				@printf "$(STYLE_RED)🚚 Lib 'Common' Compilation...\
				$(STYLE_END)\n"
				@$(MAKE) -C $(PATH_COMMON)
				@$(MAKE) -C $(PATH_COMMON) tests_criterion
				@$(MAKE) -C $(PATH_ASM) tests_criterion
				@$(MAKE) -C $(PATH_COREWAR) tests_criterion

ftest:
				@which ftest ||\
				(wget $(FTEST_REPO)releases/download/v0.1.0/$(FTEST_V) &&\
				sudo dnf -y install ftest-0.1.0-1.x86_64.rpm)
				@rm -f ftest-0.1.0-1.x86_64.rpm
				@cp ./tests/ftest/.ftest.toml .
				@ftest && rm .ftest.toml

tests_custom:
				@echo "pass"

tests_run: 		tests_criterion

coverage:
				@gcovr

coverage_branch:
				@gcovr --branch
