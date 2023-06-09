#include <assert.h>
#include "sudoku.h"

void printGrid(int **grid) {
    printf("-------------------\n");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", grid[i][j]);
            if (j % 3 == 2) {
                printf(" ");
            }
        }
        printf("\n");
        if (i % 3 == 2) {
            printf("-------------------\n");
        }
    }
}


bool isPossible(int **grid, int y, int x, int number) {
    for (int i = 0; i < 9; i++) {
        if (grid[y][i] == number) return false;
        if (grid[i][x] == number) return false;
    }
    int y0 = 3 * (y / 3);
    int x0 = 3 * (x / 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[y0 + i][x0 + j] == number) return false;
        }
    }
    return true;
}

void solve(int **grid) {
    assert(grid != NULL);
    for (int y = 0; y < 9; y++) {
        for (int x = 0; x < 9; x++) {
            if (grid[y][x] == 0) {
                for (int number = 1; number < 10; number++) {
                    if (isPossible(grid, y, x, number)) {
                        grid[y][x] = number;
                        solve(grid);
                        grid[y][x] = 0;
                    }
                }
                return;
            }
        }
    }
    printGrid(grid);
}

