//
// Created by adrianreimer on 9/30/19.
//

/*
    Good morning! Here's your coding interview problem for today.

    This problem was asked by Facebook.

    Given a list of integers, return the largest product that can be made by multiplying any three integers.

    For example, if the list is [-10, -10, 5, 2], we should return 500, since that's -10 * -10 * 5.

    You can assume the list has at least three integers.
 */

#include <stdlib.h>
#include <sort.h>
#include "day54.h"

static int cmpFunc (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

int largProd(int list[], size_t len)
{
    qsort(list, len, sizeof(int), cmpFunc);
    int num1 = list[0] * list[1] * list[len - 1];
    int num2 = list[len - 3] * list[len - 2] * list[len - 1];
    return (num1 > num2) ? num1 : num2;
}


