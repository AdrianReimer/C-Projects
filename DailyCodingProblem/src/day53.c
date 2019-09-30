//
// Created by adrianreimer on 9/30/19.
//

/*
    Good morning! Here's your coding interview problem for today.

    This problem was asked by Two Sigma.

    Using a function rand7() that returns an integer from 1 to 7 (inclusive) with uniform probability,
    implement a function rand5() that returns an integer from 1 to 5 (inclusive).
 */

#include <stdlib.h>
#include <time.h>
#include "day53.h"

static unsigned int randCnt;

int rand5()
{
    if(!randCnt++)
        srand(time(NULL));
    return rand() % 5 + 1;
}
