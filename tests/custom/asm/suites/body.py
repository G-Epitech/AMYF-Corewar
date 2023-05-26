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
suite = TestSuite("Body")

test = Test("Bad argument", "tests/utils/champions/src/bad_body/bad_argument.s", "bad_argument.cor")
suite.addTest(test)

test = Test("Bad command label", "tests/utils/champions/src/bad_body/bad_cmd.s", "bad_cmd.cor")
suite.addTest(test)

test = Test("Bad indirect alpha", "tests/utils/champions/src/bad_body/bad_indirect_alpha.s", "bad_indirect_alpha.cor")
suite.addTest(test)

test = Test("Bad placement direct label", "tests/utils/champions/src/bad_body/bad_placement_direct_label.s", "bad_placement_direct_label.cor")
suite.addTest(test)

test = Test("Bad placement indirect", "tests/utils/champions/src/bad_body/bad_placement_indirect.s", "bad_placement_indirect.cor")
suite.addTest(test)

test = Test("Bad placement register", "tests/utils/champions/src/bad_body/bad_placement_register.s", "bad_placement_register.cor")
suite.addTest(test)

test = Test("Call bad label", "tests/utils/champions/src/bad_body/call_bad_label.s", "call_bad_label.cor")
suite.addTest(test)

test = Test("Comment in command", "tests/utils/champions/src/bad_body/comment.s", "comment.cor")
suite.addTest(test)

test = Test("Indirect number", "tests/utils/champions/src/bad_body/indirect_number.s", "indirect_number.cor")
suite.addTest(test)

test = Test("Label already exists on 2 lines", "tests/utils/champions/src/bad_body/label_already_exist_diffrentes_lines.s", "label_already_exist_diffrentes_lines.cor")
suite.addTest(test)

test = Test("Label already exists", "tests/utils/champions/src/bad_body/label_already_exist.s", "label_already_exists.cor")
suite.addTest(test)

test = Test("Inexists command on label definition", "tests/utils/champions/src/bad_body/no_cmd_after_label.s", "no_cmd_after_label.cor")
suite.addTest(test)

test = Test("Inexists command on label definition with line break", "tests/utils/champions/src/bad_body/no_cmd_label_second_line.s", "no_cmd_label_second_line.cor")
suite.addTest(test)

test = Test("Too high register number", "tests/utils/champions/src/bad_body/too_high_register.s", "too_high_register.cor")
suite.addTest(test)

test = Test("Too many arguments", "tests/utils/champions/src/bad_body/too_many_args.s", "too_many_args.cor")
suite.addTest(test)

test = Test("Too labels", "tests/utils/champions/src/bad_body/two_labels.s", "two_labels.cor")
suite.addTest(test)
