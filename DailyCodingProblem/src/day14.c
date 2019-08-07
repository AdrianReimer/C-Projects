//
// Created by adrian on 07.08.2019.
//

/*
    Good morning! Here's your coding interview problem for today.

    Given a real number n, find the square root of n. For example, given n = 9, return 3.
 */

#include "day14.h"
#include <stdio.h>
#include <stdlib.h>

/* Approximates the Square Root of a number. Useless for very tiny numbers  */
double squareRoot(double number)
{
    // Newtons approximation algorithm
    if(number < 0) {
        fprintf(stderr, "Solution is not a real number.");
        exit(-1);
    }
    double approx = 10;
    for(int i = 0; i < 5; i++)
        approx = approx - ((approx * approx) - number) / (2 * approx);
    return approx;
}

