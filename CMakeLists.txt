
cmake_minimum_required(VERSION "3.9")

project("bf-transpiler")

add_executable(${PROJECT_NAME}
    "src/main.c"
    "src/bf.h"
    "src/bf.c"
    "src/stack.h"
    "src/stack.c"
)

# Add Warnings
target_compile_options(${PROJECT_NAME} PRIVATE
    "-Wall"
    "-Wextra"
    "-pedantic"
)
