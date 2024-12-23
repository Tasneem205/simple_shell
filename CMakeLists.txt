cmake_minimum_required(VERSION 3.21)
project(simple_shell C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(simple_shell
        cmds.c
        environs.c
        main.c
        main.h
        run_shell.c
        tokens.c)
