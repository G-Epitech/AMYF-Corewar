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

test = Test("Bill simple file", "tests/utils/champions/src/bill.s", "bill.cor")
suite.addTest(test)

test = Test("PDF file", "tests/utils/champions/src/pdf.s", "pdf.cor")
suite.addTest(test)

test = Test("Abel simple file", "tests/utils/champions/src/abel.s", "abel.cor")
suite.addTest(test)

test = Test("Tyron simple file", "tests/utils/champions/src/tyron.s", "tyron.cor")
suite.addTest(test)

test = Test("White simple file", "tests/utils/champions/src/white.s", "white.cor")
suite.addTest(test)

