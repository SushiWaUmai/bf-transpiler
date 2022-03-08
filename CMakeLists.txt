
cmake_minimum_required(VERSION "3.9")

project("bf-transpiler")

add_executable("bf-transpiler"
    "src/main.c"
    "src/bf.h"
    "src/bf.c"
)

# TODO: Add Warnings
# CFLAGS=-Wall -Wextra -pedantic -std=c11