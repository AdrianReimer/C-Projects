//
// Created by adrian on 25.08.2019.
//

/*
    Good morning! Here's your coding interview problem for today.

    This question was asked by ContextLogic.

    Implement division of two positive integers without using the division, multiplication, or modulus operators.
    Return the quotient as an integer, ignoring the remainder.
 */

#include "day26.h"
#include <stdlib.h>


int divide(unsigned int dividend, unsigned int divisor)
{
    int quotient = 0;
    while (divisor <= dividend) {
        dividend -= divisor;
        quotient++;
    }
    return quotient;
}
