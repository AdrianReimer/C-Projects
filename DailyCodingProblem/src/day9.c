//
// Created by adrian on 03.08.2019.
//

/*
    Good morning! Here's your coding interview problem for today.

    This problem was asked by Lyft.

    Given a list of integers and a number K, return which contiguous elements of the list sum to K.

    For example, if the list is [1, 2, 3, 4, 5] and K is 9, then it should return [2, 3, 4], since 2 + 3 + 4 = 9.
 */

#include "day9.h"
#include <stdlib.h>

int* contiguousSum(int *list, int k)
{
    int length = list[0];
    int *contiguousSum;
    int *sumStart = &list[1];
    int *sumEnd = &list[1];
    for(int i = 0; i < length; i++) {
        if(list[i] == k) {
            contiguousSum = malloc(sizeof(list[0]));
            contiguousSum[0] = list[i];
            return contiguousSum;
        }
    }
    while(sumStart != &list[length]) {
        int sum = *sumStart;
        while(sumEnd != &list[length]) {
            sum += *++sumEnd;
            if(sum == k) {
                int length = abs(&sumStart - &sumEnd);
                contiguousSum = malloc(length * sizeof(list[0]));
                for(int i = 0; i < length; i++)
                    contiguousSum[i] = *sumStart++;
                return contiguousSum;
            }
        }
        sumStart++;
        sumEnd = sumStart;
    }
}

