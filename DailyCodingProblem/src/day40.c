//
// Created by adrianreimer on 9/12/19.
//

/*
    Good morning! Here's your coding interview problem for today.

    This problem was asked by Google.

    Given an array of integers, return a new array where each element in the new array
    is the number of smaller elements to the right of that element in the original input array.

    For example, given the array [3, 4, 9, 6, 1], return [1, 1, 2, 1, 0], since:

        There is 1 smaller element to the right of 3
        There is 1 smaller element to the right of 4
        There are 2 smaller elements to the right of 9
        There is 1 smaller element to the right of 6
        There are no smaller elements to the right of 1

 */

#include <stdlib.h>
#include <stdio.h>
#include "day40.h"


int* rightSmallerElements(int *list, size_t length)
{
    if(list == NULL)
        fprintf(stderr, "list should not be NULL!");

    int *smallerEleList = malloc(sizeof(list));
    for(int i = 0; i < length; i++) {
        int number = list[i];
        size_t smallerEleCount = 0;
        for(int j = i + 1; j < length; j++) {
            if(list[j] < number)
                smallerEleCount++;
        }
        smallerEleList[i] = smallerEleCount;
    }
    return smallerEleList;
}
