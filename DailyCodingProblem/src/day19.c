//
// Created by adrian on 17.08.2019.
//

/*
    Good morning! Here's your coding interview problem for today.

    This question was asked by Google.

    Given an N by M matrix consisting only of 1's and 0's,
    find the largest rectangle containing only 1's and return its area.

    For example, given the following matrix:

    [[1, 0, 0, 0],
     [1, 0, 1, 1],
     [1, 0, 1, 1],
     [0, 1, 0, 0]]

    Return 4.
 */

#include "day19.h"

int largestRectangle(int m, int n, int arr[m][n])
{
    unsigned int recLength = 0, recWidth = 0;
    unsigned int absMax = 0, curMax = 0;
    for(int x = 0; x < m; x++) {
        for(int y = 0; y < n; y++) {
            if(arr[x][y] == 1) {
                // Diagonal
                for(int row = x; row < m; row++) {
                    if(arr[row][n] == 1)
                        curMax++;
                    else {
                        recWidth = row;
                        if(curMax > absMax)
                            absMax = curMax;
                        curMax = 0;
                        break;
                    }
                }
                // Horizontal
                for(int col = y; col < n; col++) {
                    if(arr[m][col] == 1)
                        curMax++;
                    else {
                        recLength = col;
                        if(curMax > absMax)
                            absMax = curMax;
                        curMax = 0;
                        break;
                    }
                }
                // Rectangle Horizontal
                for(int row = x; row < m; row++) {
                    for(int col = y; col < y + recWidth; col++) {
                        if(arr[row][col] != 1) {
                            row = m;
                            break;
                        }
                        else
                            curMax++;
                    }
                }
                if(curMax > absMax)
                    absMax = curMax;
                curMax = 0;
                // Rectangle Diagonal
                for(int col = y; col < n; col++) {
                    for(int row = x; row < x + recLength; row++) {
                        if(arr[row][col] != 1) {
                            col = n;
                            break;
                        }
                        else
                            curMax++;
                    }
                }
                if(curMax > absMax)
                    absMax = curMax;
                curMax = 0;
            }
        }
    }
    return absMax;
}
