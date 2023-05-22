##
## EPITECH PROJECT, 2023
## corewar
## File description:
## functions_checker
##

import os;

scan_command = "nm"
binary_array = ["asm/asm", "corewar/corewar"]
system_prefix = "_"
authorized_functions = [
    "open",
    "fopen",
    "read",
    "fread",
    "write",
    "fwrite",
    "getline",
    "lseek",
    "close",
    "fclose",
    "malloc",
    "free",
    "realloc",
    "exit"
]

def display_banned_function(name):
    print(f"Banned function: {name}")

def check_function(function):
    if len(function) < 2:
        return 0
    type = function[-2]
    name = function[-1]
    if name[0] == '_':
        name = name[1:]
    name_version = name.split("@")
    if len(name_version):
        name = name_version[0]
    if type == "U" and name not in authorized_functions and name[:1] != system_prefix:
        display_banned_function(name)
        return 1
    return 0

def check_binarys():
    status = 0

    for binary in binary_array:
        output = os.popen(f"{scan_command} {binary}").read()
        output_array = output.split("\n")

        for function in output_array:
            function_array = function.split(" ")
            new_status = check_function(function_array)
            if status == 0:
                status = new_status

    return status

exit(check_binarys())
