cmake_minimum_required(VERSION 3.24)
project(enigma2 C)

set(CMAKE_C_STANDARD 11)

add_executable(enigma rotor.h rotor.c, main.c)
