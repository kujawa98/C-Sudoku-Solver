#ifndef C_SUDOKU_SOLVER_SUDOKU_H
#define C_SUDOKU_SOLVER_SUDOKU_H

#include <stdbool.h>
#include <stdio.h>

void printGrid(int grid[9][9]);

bool isPossible(int grid[9][9], int y, int x, int number);

void solve(int grid[9][9]);

#endif
a