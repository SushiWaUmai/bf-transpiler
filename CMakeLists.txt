
cmake_minimum_required(VERSION "3.9")

project("bf-transpiler")

add_executable(${PROJECT_NAME}
    "src/main.c"
    "src/bf.h"
    "src/bf.c"
    "src/core/core.h"
    "src/core/core.c"
    "src/core/loop.h"
    "src/core/loop.c"
    "src/core/memory.h"
    "src/core/memory.c"
    "src/core/instruction.h"
    "src/core/instruction.c"
    "src/utils/stack.h"
    "src/utils/stack.c"
)

# Add Warnings
target_compile_options(${PROJECT_NAME} PRIVATE
    "-Wall"
    "-Wextra"
    "-pedantic"
)
