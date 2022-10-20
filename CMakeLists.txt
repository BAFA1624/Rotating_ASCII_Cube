cmake_minimum_required(VERSION 3.2)

project(Rotating_ASCII_Cube)

# compiler
#set(CMAKE_C_COMPILER /usr/bin/g++)

# c17 standard
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED True)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Debug & release flags
set(CMAKE_C_FLAGS_DEBUG "-Wall -Wextra -pedantic -Werror -O0 -g -ggdb -fsanitize=address -fno-omit-frame-pointer")
set(CMAKE_C_FLAGS_RELEASE "-Wall -Wextra -pedantic -Werror -O3")

# set locations to build static & shared libraries
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/libs")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

# src files & libraries
add_subdirectory(src)

add_executable(RAC src/main.c)

target_link_libraries(RAC PUBLIC points vectors transforms m)

target_include_directories(RAC PUBLIC
    "${PROJECT_BINARY_DIR}"
    "${PROJECT_SOURCE_DIR}/includes"
)
