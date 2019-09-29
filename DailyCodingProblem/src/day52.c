//
// Created by adrianreimer on 9/28/19.
//

/*
    Good morning! Here's your coding interview problem for today.

    This problem was asked by Microsoft.

    A number is considered perfect if its digits sum up to exactly 10.

    Given a positive integer n, return the n-th perfect number.

    For example, given 1, you should return 19. Given 2, you should return 28.
 */

#include <stdlib.h>
#include "day52.h"

#define PERF_NUM 10
#define MAX_UINT_FAC 1000000000 // at U_INT_MAX 4294967295


unsigned int perfNum(unsigned int n)
{
    if(n == 0)
        return 19;

    unsigned int digSum = 0;
    unsigned int num = 0;
    unsigned int numWidth = 1;
    unsigned int factor = MAX_UINT_FAC;
    while(factor >= 1) { // count digit Sum
        if(n / factor > 0) {
            digSum += (n / factor);
            num += (n / factor) * factor;
            n -= (n / factor) * factor;
            numWidth *= 10;
        }
        factor /= 10;
    }
    factor = numWidth / 10;
    while(digSum > PERF_NUM) { // cut number if needed
        if(num / factor > 0) {
            digSum -= (num / factor);
            num -= (num / factor) * factor;
        }
        factor /= 10;
    }
    if(digSum != PERF_NUM) { // concatenate a number to reach perfect number
        factor = 1;
        while(num / factor > 0)
            factor *= 10;
        num += (PERF_NUM - digSum) * factor;
    }
    return num;
}


