//
// Created by adrian on 26.08.2019.
//

/*
    Good morning! Here's your coding interview problem for today.

    This problem was asked by Apple.

    Gray code is a binary code where each successive value differ in only one bit, as well as when wrapping around.
    Gray code is common in hardware so that we don't see temporary spurious values during transitions.

    Given a number of bits n, generate a possible gray code for it.

    For example, for n = 2, one gray code would be [00, 01, 11, 10].
 */

#include "day28.h"
#include <stdlib.h>
#include <math.h>


int* generateGrayCode(unsigned int bits)
{
    unsigned int grayCount = pow(2,bits);
    int *list = malloc(grayCount * sizeof(grayCount));

    for(int i = 0; i < grayCount; i++)
        list[i] = i ^ (i >> 1);

    return list;
}