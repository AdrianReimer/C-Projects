//
// Created by adrianreimer on 2/7/20.
//

/*
    Good morning! Here's your coding interview problem for today.

    This problem was asked by Sumo Logic.

    Given an unsorted array, in which all elements are distinct, find a "peak" element in O(log N) time.

    An element is considered a peak if it is greater than both its left and right neighbors.
    It is guaranteed that the first and last elements are lower than all others.
 */

#include "day64.h"

int
findPeakElement(int arr[], size_t arrLen, size_t idx)
{
    if((idx == 0 || arr[idx - 1] < arr[idx]) &&
       (idx == arrLen - 1 || arr[idx + 1] < arr[idx])) {
        return arr[idx];
    } else if(idx > 0 && arr[idx - 1] > arr[idx]) {
        return findPeakElement(arr, arrLen, idx - 1);
    }
    return findPeakElement(arr, arrLen, idx + 1);
}
