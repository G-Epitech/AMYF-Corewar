import os
from pathlib import Path
from subprocess import PIPE, Popen

pwd = Path(__file__).parent.resolve()
projectRoot = f"{pwd}/../../../.."

class Test:
    def __init__(self, label, file, outputName) -> None:
        self.label = label
        self.file = file
        self.output = Path(outputName)
        self.execution = {
            'expected' : { 'out' : "", 'filePresent' : "", 'code': 0 },
            'found' : { 'out' : "", 'filePresent' : "", 'code': 0 }
        }

    asmModel = f"{projectRoot}/tests/utils/bin/asm"
    asm = f"{projectRoot}/asm/asm"

    def executeModel(self, file):
        command = f"{Test.asmModel} {file}"
        proc = Popen(command, stderr=PIPE, stdout=PIPE, shell=True)
        self.execution['expected']['code'] = proc.wait()
        if (not self.output.is_file()):
            self.execution['expected']['filePresent'] = False
            return
        command = f"hexdump -C {self.output.name}"
        proc = Popen(command, stderr=PIPE, stdout=PIPE, shell=True)
        if proc.wait() == 0:
            self.execution['expected']['out'] = proc.stdout.read().decode()
        os.remove(self.output.name)

    def executeUs(self, file):
        command = f"{Test.asm} {file}"
        proc = Popen(command, stderr=PIPE, stdout=PIPE, shell=True)
        self.execution['found']['code'] = proc.wait()
        if (not self.output.is_file()):
            self.execution['found']['filePresent'] = False
            return
        command = f"hexdump -C {self.output.name}"
        proc = Popen(command, stderr=PIPE, stdout=PIPE, shell=True)
        if proc.wait() == 0:
            self.execution['found']['out'] = proc.stdout.read().decode()
        os.remove(self.output.name)

    def execute(self) -> bool:
        success = True
        file = f"{projectRoot}/{self.file}"
        print(f"📄 {self.file}")
        self.executeModel(file)
        self.executeUs(file)

        if (self.execution['expected']['out'] != self.execution['found']['out']):
            success = False
            print("STDOUT:")
            print("\033[31mFound    : \n\033[0m" + self.execution['found']['out'])
            print("\033[31mExpected : \n\033[0m" + self.execution['expected']['out'])
        if (self.execution['expected']['filePresent'] != self.execution['expected']['filePresent']):
            print("CREATED FILE NOT MATCHING :")
            print("Model output file is {0} present".format('' if self.execution['expected']['filePresent'] else 'not'))
            print("Your output file is {0} present".format('' if self.execution['expected']['filePresent'] else 'not'))
        if (self.execution['expected']['code'] != self.execution['found']['code']):
            print("INVALID EXIT STATUS :")
            print("\033[31mFound    : " + str(self.execution['found']['code']) + "\033[0m")
            print("\033[31mExpected : " + str(self.execution['expected']['code']) + "\033[0m")
            success = False
        return success
