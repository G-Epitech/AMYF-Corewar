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
suite = TestSuite("Basics")

empty = Test("Bill simple file", "tests/utils/champions/src/bill.s", "bill.cor")
suite.addTest(empty)
