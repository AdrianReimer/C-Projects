//
// Created by adrian on 29.07.2019.
//

/*
    Good morning! Here's your coding interview problem for today.

    This problem was asked by Google.

    Given a sorted list of integers, square the elements and give the output in sorted order.

    For example, given [-9, -2, 0, 2, 3], return [0, 4, 4, 9, 81].
 */

#include "day4.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

static int comp (const void * ele1, const void * ele2)
{
    int f = *((int *)ele1);
    int s = *((int *)ele2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}

int* squareSort(int *list, int length)
{
    for(int i = 0; i < length; i++)
        list[i] = pow(list[i],2);

    qsort (list, length, sizeof(*list), comp);
    return list;
}


