//
// Created by adrianreimer on 10/15/19.
//

/*
    Good morning! Here's your coding interview problem for today.

    This problem was asked by Amazon.

    Given an array and a number k that's smaller than the length of the array,
    rotate the array to the right k elements in-place.
 */

#include <stdio.h>
#include <stdlib.h>
#include "day59.h"


void
rotArrRight(int arr[], size_t len, int k)
{
    if(arr == NULL) {
        fprintf(stderr, "Array should not be NULL!");
        return;
    }

    int tmp = arr[len - 1];
    for(size_t i = len - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = tmp;
    k--;

    if(k > 0) {
        rotArrRight(arr, len, k);
    }
}
