//
// Created by adrian on 05.08.2019.
//

/*
    Good morning! Here's your coding interview problem for today.

    This problem was asked by Facebook.

    Write a function that rotates a list by k elements.
    For example, [1, 2, 3, 4, 5, 6] rotated by two becomes [3, 4, 5, 6, 1, 2].

    Try solving this without creating a copy of the list.
    How many swap or move operations do you need?
 */

#include "day12.h"

void rotateList(int *list, int length, int k)
{
    int *start = list;
    int *end = &list[1];
    int temp;
    for(int i = 0; i < k % length; i++) {
        while(end != &list[length]){
            temp = *start;
            *start++ = *end;
            *end++ = temp;
        }
        start = list;
        end = &list[1];
    }
}
