#ifndef SANDPILES_H
#define SANDPILES_H


#include <stddef.h>
#include <stdio.h>
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
void printGrid(int grid[3][3]);
int isStable(int grid[3][3]);
void topple(int grid[3][3]);


#endif /* SANDPILES_H */
