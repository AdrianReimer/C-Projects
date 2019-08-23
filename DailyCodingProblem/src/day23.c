//
// Created by adrian on 23.08.2019.
//

/*
    Good morning! Here's your coding interview problem for today.

    This problem was asked by Amazon.

    Given a pivot x, and a list lst, partition the list into three parts.

    The first part contains all elements in lst that are less than x
    The second part contains all elements in lst that are equal to x
    The third part contains all elements in lst that are larger than x

    Ordering within a part can be arbitrary.

    For example, given x = 10 and lst = [9, 12, 3, 5, 14, 10, 10], one partition may be [9, 3, 5, 10, 10, 12, 14].
 */

#include "day23.h"
#include <stdio.h>

void changePivot(int x, int *list, int length)
{
    int foundPivot = 0;
    for(int i = 0; i < length; i++) {
        if(list[i] > x) {
            int temp = list[i];
            for(int idx = i; idx < length - 1; idx++)
                list[idx] = list[idx + 1];
            list[length - 1] = temp;
        } else if(list[i] < x) {
            int temp = list[i];
            for(int idx = i; idx > 0; idx--)
                list[idx] = list[idx - 1];
            list[0] = temp;
        }
    }
}