//
// Created by adrianreimer on 10/11/19.
//

/*
    Good morning! Here's your coding interview problem for today.

    This problem was asked by Google.

    You are given an array of nonnegative integers.
    Let's say you start at the beginning of the array and are trying to advance to the end.
    You can advance at most, the number of steps that you're currently on.
    Determine whether you can get to the end of the array.

    For example, given the array [1, 3, 1, 2, 0, 1],
    we can go from indices 0 -> 1 -> 3 -> 5, so return true.

    Given the array [1, 2, 1, 0, 0], we can't reach the end, so return false.
 */

#include <stdlib.h>
#include "day58.h"


int
canAdvanceToEnd(int list[], size_t len)
{
    size_t i = 0;
    while(i < len - 1) {
        int mvDist = list[i];
        if(list[i] == 0)
            return 0;
        int maxDist = i + mvDist;
        int maxDistEle = maxDist;
        int walkBack = 0;
        for(int j = maxDist - 1; j > i; j--) {
            if((list[j] - (++walkBack)) > list[maxDist]) {
                maxDist = list[j];
                maxDistEle = j;
            }
        }
        i = maxDistEle;
    }
    return 1;
}
