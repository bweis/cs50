cmake_minimum_required(VERSION 3.12)
project(cs50 C)
set(CMAKE_C_STANDARD 11)
#set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lcs50") # To ensure proper linking of cs50 library

# Problem Set 3
# see local make file