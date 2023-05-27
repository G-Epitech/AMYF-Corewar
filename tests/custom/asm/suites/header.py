##
## EPITECH PROJECT, 2023
## minishell2
## File description:
## suite
##

import pathlib
from classes.suite import TestSuite
from classes.test import Test

pwd = pathlib.Path(__file__).parent.resolve()

global suite
suite = TestSuite("Header")

test = Test("Missed first quote on comment", "tests/utils/champions/src/bad_body/first_comment.s", "first_comment.cor")
suite.addTest(test)

test = Test("Missed second quote on comment", "tests/utils/champions/src/bad_body/second_comment.s", "second_comment.cor")
suite.addTest(test)

test = Test("Missed first quote on name", "tests/utils/champions/src/bad_body/first_name.s", "first_name.cor")
suite.addTest(test)

test = Test("Missed second quote on name", "tests/utils/champions/src/bad_body/second_name.s", "second_name.cor")
suite.addTest(test)

test = Test("No quotes", "tests/utils/champions/src/bad_body/no.s", "no.cor")
suite.addTest(test)

test = Test("Comment too long", "tests/utils/champions/src/comment_too_long.s", "comment_too_long.cor")
suite.addTest(test)

test = Test("Bad word", "tests/utils/champions/src/bad_word.s", "bad_word.cor")
suite.addTest(test)
