#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "day41.h"


const int SOL[N][N] = {{7, 4, 1},
                      {8, 5, 2},
                      {9, 6, 3}};

int matrix[N][N] = {{1, 2, 3},
                   {4, 5, 6},
                   {7, 8, 9}};

int main()
{
    rotMat90(matrix);
    for(int x = 0; x < N; x++) {
        for(int y = 0; y < N; y++) {
            assert(matrix[x][y] == SOL[x][y]);
        }
    }
    return 0;
}