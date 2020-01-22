//
// Created by adrianreimer on 1/22/20.
//

/*
    Good morning! Here's your coding interview problem for today.

    This problem was asked by Stitch Fix.

    Pascal's triangle is a triangular array of integers constructed with the following formula:

        The first row consists of the number 1.
        For each subsequent row, each element is the sum of the numbers directly above it, on either side.

    For example, here are the first few rows:

        1
       1 1
      1 2 1
     1 3 3 1
    1 4 6 4 1

    Given an input k, return the kth row of Pascal's triangle.

    Bonus: Can you do this using only O(k) space?
 */

#include "day63.h"
#include <stdlib.h>
#include <assert.h>

static const uint32_t row3[] = {1, 2, 1};
static const uint32_t row7[] = {1, 6, 15, 20, 15, 6, 1};

uint32_t*
pascalTriRow(uint32_t k)
{
    uint32_t *sol = malloc(sizeof(uint32_t) * k);
    for(uint32_t row = 1; row <= k; row++) {
        uint32_t num = 1;
        for(int i = 1; i <= row; i++) {
            sol[i - 1] = num;
            num = num * (row - i) / i;
        }
    }
    return sol;
}

uint32_t
pascalTriTests()
{
    uint32_t row = 7;
    uint32_t *t1 = pascalTriRow(row);
    for(uint32_t i = 0; i < row; i++) {
        assert(t1[i] == row7[i]);
    }
    free(t1);
    row = 3;
    t1 = pascalTriRow(row);
    for(uint32_t i = 0; i < row; i++) {
        assert(t1[i] == row3[i]);
    }
    free(t1);
}
