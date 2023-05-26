#!/usr/bin/env python3

from os import system, path
from subprocess import PIPE, Popen, run
from classes.tester import Tester
import suites.basic as basic

if __name__ == '__main__':
    tester = Tester()

    tester.addSuite(basic.suite)
    if tester.execute():
        exit(0)
    else:
        exit(1)

