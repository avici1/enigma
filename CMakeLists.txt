cmake_minimum_required(VERSION 3.24)
project(enigma C)

set(CMAKE_C_STANDARD 11)

add_executable(enigma main.c plugboard.c plugboard.h reflector.c reflector.h rotors.c rotors.h)
