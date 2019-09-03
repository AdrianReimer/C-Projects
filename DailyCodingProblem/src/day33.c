//
// Created by adrian on 03.09.2019.
//

/*
    Good morning! Here's your coding interview problem for today.

    This problem was asked by Triplebyte.

    You are given n numbers as well as n probabilities that sum up to 1.
    Write a function to generate one of the numbers with its corresponding probability.

    For example, given the numbers [1, 2, 3, 4] and probabilities [0.1, 0.5, 0.2, 0.2],
    your function should return 1 10% of the time, 2 50% of the time, and 3 and 4 20% of the time.

    You can generate random numbers between 0 and 1 uniformly.
 */

#include "day33.h"
#include <stdlib.h>
#include <stdio.h>


int genRndNum(int *numbers, float *probs, int length)
{
    if(numbers == NULL || probs == NULL)
        fprintf(stderr, "numbers or probs should not be NULL!");

    float random = (float) rand() / RAND_MAX;
    float chance = 1;
    for(int i = 0; i < length; i++) {
        if(chance-=probs[i] <= random)
            return numbers[i];
    }


}
