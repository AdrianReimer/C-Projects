//
// Created by adrianreimer on 10/8/19.
//

/*
    Good morning! Here's your coding interview problem for today.

    This problem was asked by Facebook.

    Given a circular array, compute its maximum subarray sum in O(n) time.
    A subarray can be empty, and in this case the sum is 0.

    For example, given [8, -1, 3, 4], return 15 as we choose the numbers 3, 4, and 8
    where the 8 is obtained from wrapping around.

    Given [-4, 5, 1, 0], return 6 as we choose the numbers 5 and 1.
 */

#include <stdlib.h>
#include <stdio.h>
#include "day56.h"


int
maxSubarrSum(int list[], size_t len)
{
    if(list == NULL || len == 0)
        return 0;

    int SubarrSum = 0;
    int maxSubarrSum = 0;
    int *start = list;
    size_t negativeNumCnt = 0;
    int lowestNegativeNum = list[0];
    for(size_t i = 0; i < len; i++) {
        if(list[i] > 0)
            SubarrSum += list[i];
        else {
            negativeNumCnt++;
            if(list[i] > lowestNegativeNum)
                lowestNegativeNum = list[i];
            if((i + 1) < len)
                start = &list[i + 1];
            if(maxSubarrSum < SubarrSum)
                maxSubarrSum = SubarrSum;
            SubarrSum = 0;
        }
    }
    if(negativeNumCnt >= len) // array consists of only negative numbers
        return lowestNegativeNum;
    if(list[len - 1] > 0) {
        for(size_t i = 0; &list[i] != start && list[i] > 0; i++) {
            if(list[i] > 0)
                SubarrSum+= list[i];
        }
    }
    return (maxSubarrSum > SubarrSum) ? maxSubarrSum : SubarrSum;
}

