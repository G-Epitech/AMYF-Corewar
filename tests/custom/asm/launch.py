#!/usr/bin/env python3

from os import system, path
from subprocess import PIPE, Popen, run
from classes.tester import Tester
import suites.basic as basic
import suites.body as body
import suites.header as header

if __name__ == '__main__':
    tester = Tester()

    tester.addSuite(basic.suite)
    tester.addSuite(body.suite)
    tester.addSuite(header.suite)

    if tester.execute():
        exit(0)
    else:
        exit(1)

