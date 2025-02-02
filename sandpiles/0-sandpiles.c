#include <stdio.h>

void print_grid(int grid[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (j > 0) printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}

int is_stable(int grid[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] > 3) {
                return 0; // Unstable
            }
        }
    }
    return 1; // Stable
}

void topple(int grid[3][3]) {
    int temp[3][3] = {0};

    // Distribute grains to neighbors
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] > 3) {
                temp[i][j] -= 4; // Remove 4 grains from the current cell
                if (i > 0) temp[i - 1][j] += 1; // Top neighbor
                if (i < 2) temp[i + 1][j] += 1; // Bottom neighbor
                if (j > 0) temp[i][j - 1] += 1; // Left neighbor
                if (j < 2) temp[i][j + 1] += 1; // Right neighbor
            }
        }
    }

    // Apply the changes to the grid
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            grid[i][j] += temp[i][j];
        }
    }
}

void sandpiles_sum(int grid1[3][3], int grid2[3][3]) {
    // Step 1: Sum the two grids
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            grid1[i][j] += grid2[i][j];
        }
    }

    // Step 2: Check stability and topple until stable
    while (!is_stable(grid1)) {
        printf("=\n");
        print_grid(grid1);
        topple(grid1);
    }
}