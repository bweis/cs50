cmake_minimum_required(VERSION 3.12)
project(cs50 C)

set(CMAKE_C_STANDARD 11)
#set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lcs50") # To ensure proper linking of cs50 library

# Problem Set 1
add_executable(hello problem_set_1/hello.c)
add_executable(mario_easy problem_set_1/mario_easy.c)
add_executable(mario_hard problem_set_1/mario_hard.c)
add_executable(cash problem_set_1/cash.c)
add_executable(credit problem_set_1/credit.c)
