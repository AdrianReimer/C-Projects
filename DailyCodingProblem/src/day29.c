//
// Created by adrian on 28.08.2019.
//

/*
    Good morning! Here's your coding interview problem for today.

    This problem was asked by Goldman Sachs.

    Given a list of numbers L, implement a method sum(i, j)
    which returns the sum from the sublist L[i:j] (including i, excluding j).

    For example, given L = [1, 2, 3, 4, 5], sum(1, 3) should return sum([2, 3]), which is 5.

    You can assume that you can do some pre-processing. sum() should be optimized over the pre-processing step.
 */

#include <limits.h>
#include "day29.h"


int sublistSum(int *list, unsigned int length, unsigned int inclFrom, unsigned int exclTo)
{
    int sum = 0;

    if(list == NULL || inclFrom > (length - 1) || exclTo > (length - 1))
        return INT_MAX;
    while(inclFrom < exclTo)
        sum += list[inclFrom++];

    return sum;
}
