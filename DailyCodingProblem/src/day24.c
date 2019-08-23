//
// Created by adrian on 23.08.2019.
//

/*
    Good morning! Here's your coding interview problem for today.

    This problem was asked by Google.

    Given an array of numbers and an index i,
    return the index of the nearest larger number of the number at index i,
    where distance is measured in array indices.

    For example, given [4, 1, 3, 5, 6] and index 0, you should return 3.

    If two distances to larger numbers are the equal, then return any one of them.
    If the array at i doesn't have a nearest larger integer, then return null.

    Follow-up: If you can preprocess the array, can you do this in constant time?
 */

#include "day24.h"

int nearestLargerNumber(int i, int *list, int length)
{
    int number;
    int leftIdx = i;
    int rightIdx = i;

    while(leftIdx != 0 || rightIdx != length - 1) {
        if(leftIdx != 0) {
            if(list[--leftIdx] > list[i])
                return leftIdx;
        }
        if(rightIdx != length - 1) {
            if(list[++rightIdx] > list[i])
                return rightIdx;
        }
    }
    return -1;
}
