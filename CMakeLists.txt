cmake_minimum_required(VERSION 3.25)
project(C_Sudoku_Solver C)

set(CMAKE_C_STANDARD 11)

add_executable(C_Sudoku_Solver main.c sudoku.h sudoku.c)
