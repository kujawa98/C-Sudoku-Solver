#include <malloc.h>
#include "sudoku.h"
#include "reader.h"

int main() {
    int **grid = readGrid("../grid.txt");
    solve(grid);
    free(grid);
    return 0;
}
