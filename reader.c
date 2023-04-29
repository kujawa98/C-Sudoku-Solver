#include <malloc.h>
#include <stdbool.h>
#include <stdlib.h>
#include "reader.h"

int **allocateGrid();

int **readGrid(const char *fileName) {
    char buffer;
    FILE *gridFile;
    fopen_s(&gridFile, fileName, "r");
    if (NULL == gridFile) {
        printf("Unable to open file %s", fileName);
    }
    int **grid = allocateGrid();
    int x = 0;
    int y = 0;
    while (true) {
        buffer = fgetc(gridFile);
        if (buffer == '\n') {
            continue;
        } else if (buffer == EOF || y == 9) {
            break;
        }
        grid[y][x] = strtol(&buffer, NULL, 10);
        if (x == 8) {
            y++;
            x = 0;
        } else {
            x++;
        }
    }
    return grid;
}

int **allocateGrid() {
    int **grid = (int **) malloc(9 * sizeof(int *));
    for (int i = 0; i < 9; i++) {
        grid[i] = (int *) malloc(9 * sizeof(int));
    }
    return grid;
}