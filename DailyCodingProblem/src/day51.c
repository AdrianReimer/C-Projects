//
// Created by adrianreimer on 9/28/19.
//

/*
    Good morning! Here's your coding interview problem for today.

    This problem was asked by Amazon.

    Given a matrix of 1s and 0s, return the number of "islands" in the matrix.
    A 1 represents land and 0 represents water,
    so an island is a group of 1s that are neighboring whose perimeter is surrounded by water.

    For example, this matrix has 4 islands.

    1 0 0 0 0
    0 0 1 1 0
    0 1 1 0 0
    0 0 0 0 0
    1 1 0 0 1
    1 1 0 0 1
 */

#include <stdlib.h>
#include <stdio.h>
#include "day51.h"


static void changeLand(size_t x, size_t y, size_t row, size_t col, int map[x][y])
{
    if(row - 1 >= 0) {
        if (map[row - 1][col] == 1) {
            map[row - 1][col]++;
            changeLand(x, y, row - 1, col, map);
        }
    }
    if(row + 1 < x) {
        if (map[row + 1][col] == 1) {
            map[row + 1][col]++;
            changeLand(x, y, row + 1, col, map);
        }
    }
    if(col - 1 >= 0) {
        if (map[row][col - 1] == 1) {
            map[row][col - 1]++;
            changeLand(x, y, row, col - 1, map);
        }
    }
    if(col + 1 < y) {
        if (map[row][col + 1] == 1) {
            map[row][col + 1]++;
            changeLand(x, y, row, col + 1, map);
        }
    }
}

size_t islands(size_t x, size_t y, int map[x][y])
{
    size_t count = 0;
    for(size_t row = 0; row < x; row++) {
        for(size_t col = 0; col < y; col++) {
            if(map[row][col] == 1) {
                map[row][col]++;
                count++;
                changeLand(x, y, row, col, map);
            }
        }
    }
    for(size_t row = 0; row < x; row++) {
        for(size_t col = 0; col < y; col++) {
            if(map[row][col] == 2)
                map[row][col]--;
        }
    }
    return count;
}
