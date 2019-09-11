//
// Created by adrianreimer on 9/11/19.
//

/*
    Good morning! Here's your coding interview problem for today.

    This problem was asked by Google.

    You are given an array of length n + 1 whose elements belong to the set {1, 2, ..., n}.
    By the pigeonhole principle, there must be a duplicate. Find it in linear time and space.
 */

#include <stdlib.h>
#include <stdio.h>
#include "day39.h"


int findDuplicate(int *list, size_t length)
{
    if(list == NULL)
        fprintf(stderr, "list should not be NULL");

    int nFactorial = 0;
    int sum = 0;
    for(int i = 0; i < length; i++) {
        nFactorial += i;
        sum += list[i];
    }
    return sum - nFactorial;
}
