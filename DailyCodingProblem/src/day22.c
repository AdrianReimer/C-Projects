//
// Created by adrian on 20.08.2019.
//

/*
    Good morning! Here's your coding interview problem for today.

    This problem was asked by Facebook.

    Given an array of integers in which two elements appear exactly once and all other elements appear exactly twice,
    find the two elements that appear only once.

    For example, given the array [2, 4, 6, 8, 10, 2, 6, 10], return 4 and 8. The order does not matter.

    Follow-up: Can you do this in linear time and constant space?
 */

#include "day22.h"


int* singlePairAppear(int length, int *list)
{
    int arr[2], idx = 0;
    for(int i = 0; i < length && idx < 2; i++) {
        for(int k = 0; k < length; k++) {
            if(list[k] == *list && &list[k] != list) {
                break;
            } else if(k == (length - 1))
                arr[idx++] = *list;
        }
        list++;
    }
    return arr;
}