//
// Created by adrian on 28.08.2019.
//

/*
    Good morning! Here's your coding interview problem for today.

    This problem was asked by Facebook.

    Given an array of integers,
    write a function to determine whether the array could become non-decreasing by modifying at most 1 element.

    For example, given the array [10, 5, 7], you should return true,
    since we can modify the 10 into a 1 to make the array non-decreasing.

    Given the array [10, 5, 1], you should return false,
    since we can't modify any one element to get a non-decreasing array.
 */

#include "day30.h"


int isIncreasingOrder(int *list, unsigned int length)
{
    unsigned int modCount = 0;
    for(int i = 0; i < (length - 1); i++) {
        if(list[i] > list[i+1])
            if(++modCount > 1)
                return 0;
    }
    return 1;
}
